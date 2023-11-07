//
// Created by ivanf on 04/11/2023.
//

#include "imagen.h"
#include <iostream>

using namespace std;

void imagen::asignarMemoria(const int &filas, const int &columnas, rgb *buffer) {
    this->filas = filas;
    this->columnas = columnas;

    if (this->datos != nullptr)
        liberar();

    this->datos = new rgb *[filas];


    if (buffer != nullptr)
        this->datos[0] = buffer;
    else
        this->datos[0] = new rgb[filas * columnas];

    for (int i = 1; i < filas; i++)
        this->datos[i] = this->datos[i - 1] + columnas;

}

void imagen::copiar(const imagen &im) {
    asignarMemoria(im.filas, im.columnas);
    for (int i = 0; i < filas * columnas; i++)
        this->datos[0][i] = im.datos[0][i];
}

void imagen::liberar() {
    if (datos != nullptr) {
        delete[] datos[0];
        delete[] datos;
    }
}

imagen::imagen(const int &filas, const int &columnas) {
    asignarMemoria(filas, columnas);
}

imagen::imagen(const imagen &im) {
    copiar(im);
}

imagen::imagen(const char *nombre, const char *nombre_mascara) {
    LeerImagen(nombre, nombre_mascara);
}

void imagen::LeerImagen(const char *nombre, const char *nombre_mascara) {
    if (LeerTipoImagen(nombre, this->filas, this->columnas) != TipoImagen::IMG_PPM) {
        cerr << "Error: La imagen no es de tipo PPM" << endl;
        exit(2);
    }

    unsigned char *buffer = new unsigned char[this->filas * this->columnas * sizeof(rgb)];
    LeerImagenPPM(nombre, this->filas, this->columnas, buffer);

    this->asignarMemoria(this->filas, this->columnas, (rgb *) buffer);

    if (nombre_mascara != nullptr)
        this->LeerMascara(nombre_mascara);
}

void imagen::LeerMascara(const char *nombre) {
    int filas_mascara;
    int columnas_mascara;
    if (LeerTipoImagen(nombre, filas_mascara, columnas_mascara) != TipoImagen::IMG_PGM) {
        cerr << "Error: La máscara no es de tipo PGM" << endl;
        exit(2);
    }
    if (filas_mascara != this->filas || columnas_mascara != this->columnas) {
        cerr << "Error: La máscara no tiene el mismo tamaño que la imagen" << endl;
        exit(3);
    }

    unsigned char *aux = new unsigned char[filas_mascara * columnas_mascara];
    LeerImagenPGM(nombre, filas_mascara, columnas_mascara, aux);

    this->mascara = new unsigned char *[filas_mascara];
    this->mascara[0] = aux;
    for (int i = 1; i < filas_mascara; i++)
        this->mascara[i] = this->mascara[i - 1] + columnas_mascara;
}

void imagen::EscribirImagen(const char *nombre) const {
    EscribirImagenPPM(nombre, (unsigned char *) this->datos[0], this->filas, this->columnas);
}

imagen::~imagen() {
    liberar();
}

const int &imagen::Filas() const { return this->filas; }

const int &imagen::Columnas() const { return this->columnas; }

imagen &imagen::operator=(const imagen &im) {
    if (this != &im) {
        liberar();
        copiar(im);
    }
    return *this;
}

void imagen::PutImagen(const int &i, const int &j, const imagen &im, const Tipo_Pegado &tipo) {
    if (im.mascara == nullptr) {
        cerr << "Error: La imagen no tiene máscara" << endl;
        exit(1);
    }

    int parada_filas = im.filas < (this->filas - i) ? im.filas : (this->filas - i);
    int parada_columnas = im.columnas < (this->columnas - j) ? im.columnas : (this->columnas - j);

    if (tipo == OPACO) {
        for (int fila = 0; fila < parada_filas; fila++)
            for (int columna = 0; columna < parada_columnas; columna++)
                if (im.mascara[fila][columna] == 255)
                    this->datos[i + fila][j + columna] = im.datos[fila][columna];

    } else if (tipo == BLENDING) {
        for (int fila = 0; fila < parada_filas; fila++)
            for (int columna = 0; columna < parada_columnas; columna++)
                if (im.mascara[fila][columna] == 255)
                    this->datos[i + fila][j + columna] = this->datos[i + fila][j + columna].media(
                            im.datos[fila][columna]);
    }
}
