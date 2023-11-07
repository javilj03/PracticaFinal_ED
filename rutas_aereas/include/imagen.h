//
// Created by ivanf on 04/11/2023.
//

#ifndef PRACTICAFINAL_IMAGEN_H
#define PRACTICAFINAL_IMAGEN_H

#include <rgb.h>
#include "imagenES.h"
#include <iostream>

enum Tipo_Pegado {OPACO, BLENDING};

class imagen {
private:
    rgb** datos = nullptr;
    unsigned char** datos_mascara = nullptr;
    int filas = 0;
    int columnas = 0;
    int filas_mascara = 0;
    int columnas_mascara = 0;
    int max = 0;

    rgb* at(int i);
    const rgb* at(int i) const;
    rgb &at(int i, int j);
    const rgb at(int i, int j) const;

    void copiar(const imagen& im);
    void liberar();
    void asignarMemoria(int filas, int columnas, rgb* buffer = nullptr);
public:
    imagen(int filas = 0, int columnas = 0, int max = 255);
    imagen(const imagen& im);
    imagen(const char nombre[], const char *nombre_mascara = nullptr);
    ~imagen();
    imagen& operator=(const imagen& im);

    const int &Filas() const;
    const int &Columnas() const;

    void LeerImagen(const char nombre[], const char *nombre_mascara = "");
    void EscribirImagen(const char nombre[]);
    void PutImagen(const imagen& im, int i, int j, Tipo_Pegado tipo);

    const rgb* operator[](int i) const;
    rgb* operator[](int i);
};


#endif //PRACTICAFINAL_IMAGEN_H
