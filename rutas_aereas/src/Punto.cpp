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

bool Punto::operator==(const Punto& punto2) const {
   return this->x == punto2.x && this->y == punto2.y;
}

Punto coordenadas_aPunto(const double &latitud, const double &longitud, int totalfilas, int totalcolumnas) {
    double columna = (totalcolumnas / 360.0) * (180 + longitud);
    double fila = (totalfilas / 180.0) * (90 - latitud);
    return {fila, columna};
}

ostream & operator<<(ostream &os, const Punto &punto){
    os<<"("<<punto.getX()<<","<<punto.getY()<<")";

    return os;
}
istream & operator>>(istream &is,Punto &punto){
    char parentesis, coma;
    is>>parentesis>>punto.getX()>>coma>>punto.getX()>>parentesis;

    return is;
}

double &Punto::getX() {
    return this->x;
}

double &Punto::getY() {
    return this->y;
}
