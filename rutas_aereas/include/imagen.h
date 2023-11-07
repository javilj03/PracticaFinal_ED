//
// Created by ivanf on 04/11/2023.
//

#ifndef PRACTICAFINAL_IMAGEN_H
#define PRACTICAFINAL_IMAGEN_H

#include <rgb.h>
#include "imagenES.h"
#include <iostream>

enum Tipo_Pegado {
    OPACO, BLENDING
};

class imagen {
private:
    const static int MAX = 255;
    rgb **datos = nullptr;
    unsigned char **mascara = nullptr;
    int filas;
    int columnas;

    void copiar(const imagen &im);

    void liberar();

    void asignarMemoria(const int &filas, const int &columnas, rgb *buffer = nullptr);

public:
    imagen(const int &filas = 0, const int &columnas = 0);

    imagen(const imagen &im);

    imagen(const char nombre[], const char *nombre_mascara = nullptr);

    ~imagen();

    imagen &operator=(const imagen &im);

    const int &Filas() const;

    const int &Columnas() const;

    void LeerImagen(const char nombre[], const char *nombre_mascara = nullptr);

    void LeerMascara(const char nombre[]);

    void EscribirImagen(const char nombre[]) const;

    void PutImagen(const int &i, const int &j, const imagen &im, const Tipo_Pegado &tipo);

};


#endif //PRACTICAFINAL_IMAGEN_H
