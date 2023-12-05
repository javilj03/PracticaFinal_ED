#include "AlmacenRuta.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

AlmacenRuta::AlmacenRuta(const char* fileName){
    ifstream entradaRutas(fileName);
    if(!entradaRutas){
        cerr<<"Error al cargar el fichero de datos de las rutas."<< endl;
        exit(1);
    }
    this->rutas.clear();
    entradaRutas>>*this;
    entradaRutas.close();
}

void AlmacenRuta::insert(const string& nombre, const Ruta &ruta) {
   this->rutas.emplace(nombre,ruta);
}

void AlmacenRuta::erase(const string &nombre) {
   for (auto it = rutas.begin(); it != rutas.end(); ) {
      if (it->first == nombre) {
         it = rutas.erase(it);
      } else {
         ++it;
      }
   }
}

Ruta AlmacenRuta::getRuta(const string &nombre) {
   return rutas[nombre];
}

istream &operator>>(istream &is, AlmacenRuta &almacenRuta) {
   string cabecera;
   is>>cabecera;
   if(cabecera!="#Rutas"){
       cerr<<"La cabecera es incorrecta."<< endl;
       exit(1);
   }
   Ruta ruta;
   string id;
   while(is>>id){
       is>>ruta;
       almacenRuta.insert(id,ruta);
   }
   return is;
}

ostream &operator<<(ostream &os, const AlmacenRuta &almacenRuta) {
   for (AlmacenRuta::const_iterator it = almacenRuta.rutas.begin(); it != almacenRuta.rutas.end(); ++it) {
      os << "Ruta " << it.getNombreRuta() << ":\n" << it.getRuta() << "\n";
   }
   return os;
}
