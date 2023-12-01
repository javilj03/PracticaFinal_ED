
#include "Paises.h"

/**
 * @file Paises.cpp
 * @brief Implementación de la clase Paises.
 */

using namespace std;

const string Paises::CABECERA = "# Latitud\t\t\tLongitud\t\t\tPais\t\tBandera";

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

Paises::Paises(const char *fileName) {
    this->insertar(fileName);
}

bool Paises::empty() const {
    return this->datos.empty();
}

bool Paises::insert(Pais pais) {
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

bool Paises::Iterator::operator!=(Paises::Iterator it2) const {
    return this->iterador != it2.iterador;
}

Paises::Iterator::Iterator() {
    this->iterador = set<Pais>::iterator();
}

Pais Paises::Iterator::operator*() const {
    return *this->iterador;
}

ostream &operator<<(ostream &os, const Paises &paises) {
    for (Paises::const_Iterator i = paises.begin(); i != paises.end(); i++)
        os << std::setprecision(16) << *i << endl;
    return os;
}

istream &operator>>(istream &is, Paises &paises) {
    string cabecera;
    Pais nuevoPais;

    getline(is, cabecera);
    while (is >> nuevoPais)
        paises.insert(nuevoPais);

    return is;
}

Paises::Iterator::Iterator(const Paises::Iterator &other) {
    this->iterador = other.iterador;
}

Paises::Iterator::Iterator(const set<Pais>::iterator &it) {
    this->iterador = it;
}


Paises::const_Iterator Paises::begin() const {
    return {this->datos.begin()};
}

Paises::Iterator Paises::begin() {
    return {this->datos.begin()};
}

Paises::Iterator Paises::end() {
    return {this->datos.end()};
}

Paises::const_Iterator Paises::end() const {
    return {this->datos.end()};
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

Paises::Iterator Paises::find(const Pais &pais) const {
    return {this->datos.find(pais)};
}