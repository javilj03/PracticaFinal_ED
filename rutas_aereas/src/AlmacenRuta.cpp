#include "AlmacenRuta.h"
#include <sstream>

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

istream &operator>>(istream &is, AlmacenRuta &almacenRuta) {
   string linea;

   getline(is, linea);

   while (getline(is, linea)) {
      if (linea.empty()) {
         continue;
      }

      istringstream iss(linea);
      string rutaIdentificador;
      iss >> rutaIdentificador;

      if (rutaIdentificador[0] == 'R' && isdigit(rutaIdentificador[1])) {
         Ruta ruta;
         iss >> ruta;
         almacenRuta.insert(rutaIdentificador, ruta);
      }
   }

   return is;
}

ostream &operator<<(ostream &os, const AlmacenRuta &almacenRuta) {
   for (AlmacenRuta::const_iterator it = almacenRuta.rutas.begin(); it != almacenRuta.rutas.end(); ++it) {
      os << "Ruta " << it.getNombreRuta() << ":\n" << it.getRuta() << "\n";
   }
   return os;
}
