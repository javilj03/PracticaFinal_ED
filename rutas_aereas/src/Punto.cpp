#include "Punto.h"

/**
 * @file getPunto.cpp
 * @brief Implementación de la clase getPunto.
 * @author Iván Rodríguez Chacón
 * @author Javier Lama Jiménez
 */
int Punto::total_filas=768;
int Punto::total_columnas=1536;
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
    double auxX,auxY;
    is>>parentesis>>auxX>>coma>>auxY>>parentesis;
    punto = coordenadas_aPunto(auxX,auxY, punto.getTotalFilas(), punto.getTotalColumnas());
    return is;
}

pair<double, double> punto_aCoordenadas(const Punto &punto, const int &totalfilas, const int &totalcolumnas) {
    double latitud = 90 - (punto.getX() / ((double)totalfilas / 180.0));
    double longitud = (punto.getY() / ((double)totalcolumnas / 360.0)) - 180;
    return {latitud, longitud};
}

double &Punto::getX() {
    return this->x;
}

double &Punto::getY() {
    return this->y;
}

int Punto::getTotalColumnas() const {
    return Punto::total_columnas;
}

int Punto::getTotalFilas() const {
    return Punto::total_filas;
}
