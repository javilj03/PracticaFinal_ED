//
// Created by ivanf on 04/11/2023.
//

#include "imagen.h"
#include <iostream>

using namespace std;

void imagen::asignarMemoria(int filas, int columnas) {
    this->columnas = columnas;
    this->filas = filas;
    this->datos = new rgb *[filas];
    this->datos[0] = new rgb[filas * columnas];
    for (int i = 1; i < filas; i++)
        this->datos[i] = this->datos[i - 1] + columnas;
}

void imagen::liberar() {
    if (this->datos != nullptr) {
        delete[] this->datos[0];
        delete[] this->datos;
        this->datos = nullptr;
    }
    if (this->datos_mascara != nullptr) {
        for (int i = 0; i < this->filas_mascara; i++)
            delete[] this->datos_mascara[i];
        delete[] this->datos_mascara;
        this->datos_mascara = nullptr;
    }
}

void imagen::copiar(const imagen &im) {
    this->filas = im.filas;
    this->columnas = im.columnas;
    this->max = im.max;
    this->asignarMemoria(filas, columnas);

    for (int i = 0; i < this->filas; i++)
        for (int j = 0; j < this->columnas; j++)
            this->datos[i][j] = im.datos[i][j];
}
imagen::imagen(int filas, int columnas, int max) {
    asignarMemoria(filas, columnas);
    this->filas = filas;
    this->columnas = columnas;
    this->max = max;
}
imagen::imagen(const imagen &im) {
    this->copiar(im);
}
imagen::imagen(const char *nombre, const char *nombre_mascara) {
    this->LeerImagen(nombre, nombre_mascara);
}
imagen::~imagen() {
    this->liberar();
}
imagen &imagen::operator=(const imagen &im) {
    if (this != &im) {
        this->liberar();
        this->copiar(im);
    }
    return *this;
}
const int &imagen::Filas() const {
    return this->filas;
}
const int &imagen::Columnas() const {
    return this->columnas;
}
rgb *imagen::at(int i) {
    if(i < this->filas && i >= 0)
        return this->datos[i];
    else
        throw out_of_range("El indice esta fuera de rango");
}
const rgb *imagen::at(int i) const {
    if (i < this->filas && i >= 0)
        return this->datos[i];
    else
        throw out_of_range("El indice esta fuera de rango");
}
rgb &imagen::at(int i, int j) {
    if(i < this->filas && i >= 0 && j < this->columnas && j >= 0)
        return this->datos[i][j];
    else
        throw out_of_range("El indice esta fuera de rango");
}
const rgb imagen::at(int i, int j) const {
    if (i < this->filas && i >= 0 && j < this->columnas && j >= 0)
        return this->datos[i][j];
    else
        throw out_of_range("El indice esta fuera de rango");
}

const rgb *imagen::operator[](int i) const {
    return this->at(i);
}
rgb *imagen::operator[](int i) {
    return this->at(i);
}

void imagen::LeerImagen(const char *nombre, const char *nombre_mascara) {
    //this->liberar();
    LeerTipoImagen(nombre, this->filas, this->columnas);
    LeerImagenPPM(nombre, this->filas,this->columnas, reinterpret_cast<unsigned char *>(this->datos));
    if(nombre_mascara != "" && LeerTipoImagen(nombre_mascara, this->filas, this->columnas) == IMG_PGM)
        LeerImagenPGM(nombre_mascara, this->filas_mascara, this->columnas_mascara, this->datos_mascara[0]);
}

void imagen::EscribirImagen(const char *nombre) {
    EscribirImagenPPM(nombre, reinterpret_cast<unsigned char *>(this->datos[0]), this->filas, this->columnas);
}
/*void imagen::PutImagen(const imagen &im, int i, int j, Tipo_Pegado tipo) {
    if(tipo == OPACO){
        for(rgb pixel)
    }
    else{

    }
}*/