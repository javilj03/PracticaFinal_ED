#include "AlmacenRutas.h"

AlmacenRuta::AlmacenRuta() {}

void AlmacenRuta::insert(std::string nombre, Ruta &ruta) {
   this->rutas.emplace(nombre,ruta);
}

void AlmacenRuta::erase(string nombre) {
   for (auto it = rutas.begin(); it != rutas.end(); ) {
      if (it->first == nombre) {
         it = rutas.erase(it);
      } else {
         ++it;
      }
   }
}

Ruta AlmacenRuta::getRuta(std::string nombre) {
   return rutas[nombre];
}
