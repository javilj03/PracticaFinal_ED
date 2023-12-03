#include <iostream>
#include <algorithm>
#include "Ruta.h"
#include "Punto.h"
using namespace std;


void Ruta::insert(Punto punto) {
   puntos.push_back(punto);
}

void Ruta::erase(Punto punto) {
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

   return is;
}

ostream &operator<<(std::ostream &os, const Ruta &ruta) {

   os << " " << ruta.puntos.size() << " ";
   for(int i = 0; i < ruta.puntos.size(); i++){
      os << ruta.puntos[i];
   }

   return os;
}

Punto &Ruta::operator[](const int &i) {
    return this->puntos[i];
}

const Punto &Ruta::operator[](const int &i) const {
    return this->puntos[i];
}
