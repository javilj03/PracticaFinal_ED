//
// Created by ivan on 27/11/23.
//

#include "Paises.h"

using namespace std;

void Paises::insertar(const char *fileName) {
    ifstream file(fileName);
    if(!file){
        cerr<<"Ocurrió un error al abrir el fichero";
        exit(-1);
    }
    if(!file.is_open()){
        cerr<<"El programa tuvo un problema al intentar leer el fichero";
        exit(-2);
    }
    file>>*this;
    file.close();
}

Paises::Paises(const char *fileName) {
    this->insertar(fileName);
}

bool Paises::empty() const {
    return this->datos.empty();
}

bool Paises::insert(const pair<string, Pais>& elemento) {
    return this->datos.insert(elemento).second;
}

bool Paises::insert(Pais pais) {
    return this->datos.emplace(pais.Nombre(),pais).second;
}

Paises::Iterator &Paises::Iterator::operator++() {
    ++this->iterador;
    return *this;
}

Paises::Iterator &Paises::Iterator::operator++(int) {
    this->iterador++;
    return *this;
}

void Paises::insert(const Paises::Iterator& begin, const Paises::Iterator& end) {
    for(Paises::Iterator i = begin;i!=end;i++)
        this->insert(*i);
}

bool Paises::Iterator::operator!=(Paises::Iterator it2) const{
    return this->iterador != it2.iterador;
}

Paises::Iterator::Iterator() {
    this->iterador = map<string,Pais>::iterator();
}

pair<string, Pais> Paises::Iterator::operator*() {
    return *this->iterador;
}

ostream &operator<<(ostream &os, const Paises &paises) {
    os<<"# Latitud         	Longitud 	      	Pais      	Bandera"<<endl;
    for(Paises::const_Iterator i=paises.begin();i!=paises.end();i++)
        os<<(*i).second<<endl;
    return os;
}

istream &operator>>(istream &is, Paises &paises) {
    string basura;
    Pais nuevoPais;
    is>>basura>>basura>>basura>>basura>>basura;
    while(is>>nuevoPais)
        paises.insert(nuevoPais);

    return is;
}

Paises::Iterator::Iterator(const Paises::Iterator &other){
    this->iterador = other.iterador;
}
Paises::Iterator::Iterator(const map<string, Pais>::iterator &it){
    this->iterador = it;
}



Paises::const_Iterator Paises::begin() const {
    return {this->datos.begin()};
}

Paises::const_Iterator Paises::end() const {
    return {this->datos.end()};
}

Paises::const_Iterator::const_Iterator(const map<string, Pais>::const_iterator &it) {
    this->iterador = it;
}

Paises::const_Iterator &Paises::const_Iterator::operator++() {
    ++this->iterador;
    return *this;
}

Paises::const_Iterator &Paises::const_Iterator::operator++(int) {
    this->iterador++;
    return *this;
}

pair<string, Pais> Paises::const_Iterator::operator*() {
    return *this->iterador;
}

bool Paises::const_Iterator::operator!=(Paises::const_Iterator it2) const {
    return this->iterador != it2.iterador;
}
