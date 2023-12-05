#include "AlmacenRuta.h"

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
   this->rutas.erase(nombre);
}

Ruta AlmacenRuta::getRuta(const string &nombre) {
   return rutas.at(nombre);
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
   for (AlmacenRuta::const_iterator it= almacenRuta.cbegin();it!=almacenRuta.cend(); ++it)
      os << "Ruta " << it.getNombreRuta() << ":\n" << it.getRuta() << "\n";

   return os;
}

AlmacenRuta::iterator AlmacenRuta::begin() {
    iterator i;
    i.it = rutas.begin();
    return i;
}

AlmacenRuta::iterator AlmacenRuta::end() {
    iterator i;
    i.it = rutas.end();
    return i;
}

Ruta &AlmacenRuta::operator[](const string &nombre) {
    return this->rutas[nombre];
}

const Ruta &AlmacenRuta::operator[](const string &nombre) const {
    return this->rutas.at(nombre);
}

int AlmacenRuta::size() const {
    return this->rutas.size();
}

AlmacenRuta::const_iterator AlmacenRuta::cbegin() const {
    return {rutas.cbegin()};
}

AlmacenRuta::const_iterator AlmacenRuta::cend() const {
    return {rutas.cend()};
}
