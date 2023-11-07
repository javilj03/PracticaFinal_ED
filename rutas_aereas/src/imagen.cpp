//
// Created by ivanf on 04/11/2023.
//

#include "imagen.h"
#include <iostream>

using namespace std;

void imagen::asignarMemoria(int filas, int columnas,rgb *buffer) {
    this->filas = filas;
    this->columnas = columnas;

    this->datos = new rgb*[filas];


    if (buffer!= nullptr)
        this->datos[0] = buffer;
    else
        this->datos[0] = new rgb[filas*columnas];

    for (int i = 1; i < filas; i++)
        this->datos[i] = this->datos[i-1] + columnas;

}

void imagen::copiar(const imagen &im) {
    asignarMemoria(im.filas, im.columnas);
    for (int i = 0; i < filas*columnas; i++)
        this->datos[0][i] = im.datos[0][i];
}

void imagen::liberar() {
    if (datos != nullptr) {
        delete[] datos[0];
        delete[] datos;
    }
}

imagen::imagen(int filas, int columnas, int max) {
    asignarMemoria(filas, columnas);
    this->max = max;
}

imagen::imagen(const imagen &im) {
    copiar(im);
}

imagen::imagen(const char *nombre, const char *nombre_mascara) {
    LeerImagen(nombre, nombre_mascara);
}

void imagen::LeerImagen(const char *nombre, const char *nombre_mascara) {
    int filas_mascara = 0, columnas_mascara = 0;
    LeerTipoImagen(nombre, this->filas, this->columnas);
    unsigned char * buffer = new unsigned char[this->filas * this->columnas * 3];
    LeerImagenPPM(nombre, this->filas, this->columnas,buffer);
    this->asignarMemoria(this->filas, this->columnas, (rgb*)buffer);
    if(nombre_mascara!= nullptr)
        if(LeerTipoImagen(nombre_mascara,filas_mascara,columnas_mascara) == TipoImagen::IMG_PGM)
            if(filas_mascara == this->filas && columnas_mascara == this->columnas) {
                unsigned char *mascara = new unsigned char[filas_mascara * columnas_mascara];
                LeerImagenPGM(nombre_mascara, filas_mascara, columnas_mascara, mascara);

                for(int i = 0; i < filas; i++)
                    for(int j = 0; j < columnas; j++)
                        if(mascara[i*columnas + j] == 0)
                            this->datos[i][j].set(0,0,0);
            }

}

void imagen::EscribirImagen(const char *nombre) {
    EscribirImagenPPM(nombre, (unsigned char*)this->datos[0], this->filas, this->columnas);
}

rgb &imagen::at(int i, int j) {
    if(i > 0 && i < this->filas && j > 0 && j < this->columnas)
        return this->datos[i][j];
    else
        throw std::out_of_range("Ocurrió un error al acceder a una posición de la imagen");
}

const rgb imagen::at(int i, int j) const {
    return this->at(i, j);
}

rgb *imagen::at(int i) {
    if(i > 0 && i < this->filas)
        return this->datos[i];
    else
        throw std::out_of_range("Ocurrió un error al acceder a una posición de la imagen");
}
const rgb *imagen::at(int i) const {
    if(i > 0 && i < this->filas)
        return this->datos[i];
    else
        throw std::out_of_range("Ocurrió un error al acceder a una posición de la imagen");
}

imagen::~imagen() {
    liberar();
}

const int &imagen::Filas() const {  return this->filas; }
const int &imagen::Columnas() const { return this->columnas; }

imagen &imagen::operator=(const imagen &im) {
    if (this != &im) {
        liberar();
        copiar(im);
    }
    return *this;
}

rgb *imagen::operator[](int i) {
    return this->at(i);
}

const rgb *imagen::operator[](int i) const {
    return this->at(i);
}

void imagen::PutImagen(int i, int j, const imagen &im, Tipo_Pegado tipo) {
    int cero =0;
    if (tipo == OPACO) {
        for (int fila = 0; fila < im.filas && fila < this->filas; fila++)
            for (int columna = 0; columna < im.columnas && fila < this->columnas; columna++)

                if(im.datos[i+fila][j+columna]!=0)
                    this->datos[i+fila][j + columna] = im.datos[i+fila][j + columna];
    } else if (tipo == BLENDING) {
        for (int fila = 0; fila < im.filas && fila < this->filas; fila++)
            for (int columna = 0; columna < im.columnas && fila < this->columnas; columna++)
                this->datos[i+fila][j + columna] = (this->datos[i+fila][j + columna] + im.datos[i+fila][j + columna])/ 2;
    }
}