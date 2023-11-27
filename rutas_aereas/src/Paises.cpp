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

Paises::Iterator Paises::begin() const {
    return Paises::Iterator(this->datos.begin());

Paises::Iterator Paises::end() const {
    return Paises::Iterator();
}

bool Paises::empty() const {
    return false;
}

bool Paises::insert(pair<string, Pais>) {
    return false;
}

bool Paises::insert(Pais) {
    return false;
}

bool Paises::insert(Paises::Iterator begin, Paises::Iterator end) {
    return false;
}

Paises::Iterator::Iterator() {
    this->iterador = map<string,Pais>::iterator();
}

Paises::Iterator Paises::Iterator::operator++() {
    return Paises::Iterator();
}

pair<string, Pais> Paises::Iterator::operator*() {
    return pair<string, Pais>();
}

ostream &operator<<(ostream &os, const Paises &paises) {
    return os;
}

istream &operator>>(istream &is, Paises &paises) {
    return is;
}
    Paises::Iterator Paises::Iterator::operator++() {
        return Paises::Iterator();
    }
    Paises::Iterator::Iterator()
    {

    }
    Paises::Iterator::Iterator(const Paises::Iterator &other){

    }
    Paises::Iterator::Iterator(const map<string, Pais>::iterator &it){
        this->iterador = it;
    }
    Paises::Iterator Paises::Iterator::operator++() {
        return Paises::Iterator();
    }
    pair<string, Pais> Paises::Iterator::operator*() {
        return pair<string, Pais>();
    }
