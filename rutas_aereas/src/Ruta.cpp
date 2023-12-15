#include <iostream>
#include <algorithm>
#include "Ruta.h"
#include "Punto.h"

using namespace std;


void Ruta::insert(const Punto &punto) {
    puntos.push_back(punto);
}

void Ruta::erase(const Punto &punto) {
    auto it = find(puntos.begin(), puntos.end(), punto);
    if (it != puntos.end()) {
        puntos.erase(it);
    }
}

void Ruta::erase(iterator it) {
    puntos.erase(it.it);
}

vector<Punto> Ruta::getPuntos() {
    return puntos;
}


//***********************************************************************************
// Implementación de los operadores de entrada/salida
istream &operator>>(std::istream &is, Ruta &ruta) {
    int numPuntos;
    is >> numPuntos;
    ruta.puntos.clear();

    Punto punto;

    for (int i = 0; i < numPuntos; ++i) {
        is >> punto;
        ruta.puntos.push_back(punto);
    }
    //fix this loop to insert the middle points
    for (int i = 0; i < ((numPuntos * 2) - 2); i += 2) {

        double x_medio = (ruta.puntos[i].getX() + (ruta.puntos[i + 1]).getX()) / 2;
        double y_medio = (ruta.puntos[i].getY() + ruta.puntos[i + 1].getY()) / 2;

        ruta.insert(i + 1, Punto(x_medio, y_medio));
    }
    return is;
}

ostream &operator<<(std::ostream &os, const Ruta &ruta) {


    os << " " << (ruta.size() / 2) + 1 << " ";
    for (int i = 0; i < ruta.size(); i += 2) {
        os << "(" << punto_aCoordenadas(ruta[i]).first << ","
           << punto_aCoordenadas(ruta[i]).second << ")";
    }

    return os;
}

Ruta::iterator Ruta::begin() {
    iterator i;
    i.it = puntos.begin();
    return i;
}

Ruta::iterator Ruta::end() {
    iterator i;
    i.it = puntos.end();
    return i;
}

void Ruta::insert(const int &pos, const Punto &punto) {
    puntos.insert(puntos.begin() + pos, punto);
}


Punto &Ruta::operator[](const int &i) {
    return this->puntos[i];
}

const Punto &Ruta::operator[](const int &i) const {
    return this->puntos[i];
}

int Ruta::size() const {
    return this->puntos.size();
}