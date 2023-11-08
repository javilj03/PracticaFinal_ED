#include "Imagen.h"

/**
 * @file Imagen.cpp
 * @brief Implementación de la clase Imagen.
 * @author Iván Rodríguez Chacón
 */

using namespace std;

void Imagen::asignarMemoria(const int &filas, const int &columnas, Pixel *buffer) {
    this->filas = filas;
    this->columnas = columnas;
    if (filas != 0 && columnas != 0) {
        liberar();

        this->datos = new Pixel *[filas];


        if (buffer != nullptr)
            this->datos[0] = buffer;
        else
            this->datos[0] = new Pixel[filas * columnas];

        for (int i = 1; i < filas; i++)
            this->datos[i] = this->datos[i - 1] + columnas;
    } else
        this->datos = nullptr;
}

void Imagen::copiar(const Imagen &im) {
    asignarMemoria(im.filas, im.columnas);
    for (int i = 0; i < filas * columnas; i++)
        this->datos[0][i] = im.datos[0][i];
}

void Imagen::liberar() {
    if (datos != nullptr) {
        delete[] datos[0];
        delete[] datos;
    }
}

Imagen::Imagen(const int &filas, const int &columnas) {
    asignarMemoria(filas, columnas);
}

Imagen::Imagen(const Imagen &im) {
    copiar(im);
}

Imagen::Imagen(const char *nombre, const char *nombre_mascara) {
    LeerImagen(nombre, nombre_mascara);
}

void Imagen::LeerImagen(const char *nombre, const char *nombre_mascara) {
    if (LeerTipoImagen(nombre, this->filas, this->columnas) != TipoImagen::IMG_PPM) {
        cerr << "Error: La Imagen no es de tipo PPM" << endl;
        exit(2);
    }

    unsigned char *buffer = new unsigned char[this->filas * this->columnas * sizeof(Pixel)];
    LeerImagenPPM(nombre, this->filas, this->columnas, buffer);

    this->asignarMemoria(this->filas, this->columnas, (Pixel *) buffer);

    if (nombre_mascara != nullptr)
        this->LeerMascara(nombre_mascara);
}

void Imagen::LeerMascara(const char *nombre) {
    int filas_mascara;
    int columnas_mascara;
    if (LeerTipoImagen(nombre, filas_mascara, columnas_mascara) != TipoImagen::IMG_PGM) {
        cerr << "Error: La máscara no es de tipo PGM" << endl;
        exit(2);
    }
    if (filas_mascara != this->filas || columnas_mascara != this->columnas) {
        cerr << "Error: La máscara no tiene el mismo tamaño que la Imagen" << endl;
        exit(3);
    }

    unsigned char *aux = new unsigned char[filas_mascara * columnas_mascara];
    LeerImagenPGM(nombre, filas_mascara, columnas_mascara, aux);

    this->mascara = new unsigned char *[filas_mascara];
    this->mascara[0] = aux;
    for (int i = 1; i < filas_mascara; i++)
        this->mascara[i] = this->mascara[i - 1] + columnas_mascara;
}

void Imagen::EscribirImagen(const char *nombre) const {
    EscribirImagenPPM(nombre, (unsigned char *) this->datos[0], this->filas, this->columnas);
}

Imagen::~Imagen() {
    liberar();
}

const int &Imagen::Filas() const { return this->filas; }

const int &Imagen::Columnas() const { return this->columnas; }

Imagen &Imagen::operator=(const Imagen &im) {
    if (this != &im) {
        liberar();
        copiar(im);
    }
    return *this;
}

void Imagen::PutImagen(const int &i, const int &j, const Imagen &im, const Tipo_Pegado &tipo) {
    if (im.mascara == nullptr) {
        cerr << "Error: La Imagen no tiene máscara" << endl;
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

Pixel &Imagen::operator()(const int &i, const int &j) {
    if (i < 0 || i >= this->filas || j < 0 || j >= this->columnas)
        throw std::out_of_range("Error: Índices fuera de rango");

    return this->datos[i][j];
}

const Pixel &Imagen::operator()(const int &i, const int &j) const {
    if (i < 0 || i >= this->filas || j < 0 || j >= this->columnas)
        throw std::out_of_range("Error: Índices fuera de rango");

    return this->datos[i][j];
}