#include "Punto.h"

/**
 * @file Punto.cpp
 * @brief Implementación de la clase Punto.
 * @author Iván Rodríguez Chacón
 * @author Javier Lama Jiménez
 */
Punto::Punto(double x, double y) {
    this->x = x;
    this->y = y;
}

double Punto::getX() const {
    return x;
}

double Punto::getY() const {
    return y;
}

bool operator==(const Punto& punto1, const Punto& punto2) {
   return punto1.x == punto2.x && punto1.y == punto2.y;
}

Punto coordenadas_aPunto(const double &latitud, const double &longitud, int totalfilas, int totalcolumnas) {
    double columna = (totalcolumnas / 360.0) * (180 + longitud);
    double fila = (totalfilas / 180.0) * (90 - latitud);
    return Punto(fila, columna);
}

ostream & operator<<(ostream &os, const Punto &punto){
    os<<"("<<punto.x<<","<<punto.y<<")";

    return os;
}
istream & operator>>(istream &is,Punto &punto){
    char parentesis, coma;
    is>>parentesis>>punto.x>>coma>>punto.y>>parentesis;

    return is;
}