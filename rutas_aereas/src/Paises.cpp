
#include "Paises.h"

/**
 * @file Paises.cpp
 * @brief Implementación de la clase Paises.
 */

using namespace std;

const string Paises::CABECERA = "# Latitud\t\t\tLongitud\t\t\tPais\t\tBandera";
string Paises::dir_banderas;

void Paises::insertar(const char *fileName) {
    ifstream file(fileName);
    if (!file) {
        cerr << "Ocurrió un error al abrir el fichero";
        exit(-1);
    }
    if (!file.is_open()) {
        cerr << "El programa tuvo un problema al intentar leer el fichero";
        exit(-2);
    }

    file >> *this;

    file.close();
}

Paises::Paises(const char *fileName, const char *dir_banderas) {
    Paises::dir_banderas = dir_banderas;
    this->insertar(fileName);
}

bool Paises::empty() const {
    return this->datos.empty();
}

bool Paises::insert(const Pais& pais) {
    return this->datos.insert(pais).second;
}

Paises::Iterator &Paises::Iterator::operator++() {
    ++this->iterador;
    return *this;
}

Paises::Iterator &Paises::Iterator::operator++(int) {
    this->iterador++;
    return *this;
}

void Paises::insert(const Paises::Iterator &begin, const Paises::Iterator &end) {
    for (Paises::Iterator i = begin; i != end; i++)
        this->insert(*i);
}

bool Paises::Iterator::operator!=(const Paises::Iterator& it2) const {
    return this->iterador != it2.iterador;
}

Paises::Iterator::Iterator() {
    this->iterador = set<Pais>::iterator();
}

Pais Paises::Iterator::operator*() const {
    return *this->iterador;
}

ostream &operator<<(ostream &os, const Paises &paises) {
    for (Paises::const_Iterator i = paises.cbegin(); i != paises.cend(); i++)
        os << std::setprecision(20) << *i << endl;
    return os;
}

istream &operator>>(istream &is, Paises &paises) {
    string cabecera;

    Pais nuevoPais("",paises.getDir_banderas());
    getline(is, cabecera);
    while (is >> nuevoPais) {
        paises.insert(nuevoPais);
        nuevoPais = Pais("",paises.getDir_banderas());
    }
    return is;
}

Paises::Iterator::Iterator(const Paises::Iterator &other) {
    this->iterador = other.iterador;
}

Paises::Iterator::Iterator(const set<Pais>::iterator &it) {
    this->iterador = it;
}


Paises::const_Iterator Paises::cbegin() const {
    return {this->datos.cbegin()};
}

Paises::Iterator Paises::begin() {
    return {this->datos.begin()};
}

Paises::Iterator Paises::end() {
    return {this->datos.end()};
}

Paises::const_Iterator Paises::cend() const {
    return {this->datos.cend()};
}

void Paises::erase(const Pais &pais) {
    this->datos.erase(pais);
}

void Paises::erase(const Paises::Iterator &it) {
    this->erase(*it);
}

Paises::const_Iterator::const_Iterator(const set<Pais>::const_iterator &it) {
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

Pais Paises::const_Iterator::operator*() const {
    return *this->iterador;
}

bool Paises::const_Iterator::operator!=(Paises::const_Iterator it2) const {
    return this->iterador != it2.iterador;
}

void Paises::clear() {
    this->datos.clear();
}

void Paises::save(const char *fileName) const {
    ofstream file(fileName);
    if (!file) {
        cerr << "Ocurrió un error al abrir el fichero";
        exit(-1);
    }
    if (!file.is_open()) {
        cerr << "El programa tuvo un problema al intentar leer el fichero";
        exit(-2);
    }
    file << CABECERA << endl;
    file << *this;
    file.close();
}
Paises::const_Iterator Paises::find(const Punto &punto) const {
    for(Paises::const_Iterator i = this->cbegin(); i != this->cend(); i++)
        if((*i).getPunto() == punto)
            return i;
    return this->cend();
}
Paises::Iterator Paises::find(const Pais &pais) const {
    return {this->datos.find(pais)};
}

string Paises::getDir_banderas() {
    return dir_banderas;
}
