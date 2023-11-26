#include <iostream>
#include <algorithm>
#include "Ruta.h"
#include "Punto.h"
using namespace std;
Ruta::Ruta() {}

void Ruta::insert(Punto punto) {
   puntos.push_back(punto);
}

void Ruta::erase(Punto punto) {
   auto it = find(puntos.begin(), puntos.end(), punto);
   if (it != puntos.end()) {
      puntos.erase(it);
   }
}
//Creo tambien erase que reciba un iterador
void Ruta::erase(iterator it) {
puntos.erase(it.it);
}

void Ruta::setCode(string code) {
   this->code = code;
}

vector<Punto> Ruta::getPuntos() {
   return puntos;
}


//***********************************************************************************
// Implementación de los operadores de entrada/salida
istream &operator>>(std::istream &is, Ruta &ruta) {

   return is;
}

ostream &operator<<(std::ostream &os, const Ruta &ruta) {


   return os;
}
