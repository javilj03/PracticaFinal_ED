#include "Pais.h"

/**
 * @file Pais.cpp
 * @brief Implementación de la clase Pais.
 */

Pais::Pais(const string &nombre, const string &path_bandera,const Punto &punto) {
    this->asignar(nombre, path_bandera, punto);
}

Pais::Pais(const Pais &pais) {
    this->copiar(pais);
}

Pais &Pais::operator=(const Pais &pais) {
    if (this != &pais) {
        this->copiar(pais);
    }
    return *this;
}

const string &Pais::Nombre() const {
    return this->nombre;
}

string &Pais::Nombre() {
    return this->nombre;
}

const string &Pais::PathBandera() const {
    return this->path_bandera;
}

string &Pais::PathBandera() {
    return this->path_bandera;
}

const Punto &Pais::getPunto() const {
    return this->punto;
}

Punto &Pais::getPunto() {
    return punto;
}


Imagen &Pais::Bandera() {
    if (this->bandera.Filas() == 0 || this->bandera.Columnas() == 0)
        this->bandera = Imagen(this->path_bandera.c_str());

    return this->bandera;
}

void Pais::asignar(const string &nombre, const string &path_bandera, const Punto &punto) {
    this->nombre = nombre;
    this->path_bandera = path_bandera;
    this->punto = punto;
}

void Pais::copiar(const Pais &pais) {
    this->asignar(pais.nombre, pais.path_bandera, pais.punto);
    if (pais.bandera.Filas() != 0 && pais.bandera.Columnas() != 0)
        this->bandera = pais.bandera;
}



bool Pais::operator<(const Pais &pais) const {
    return this->nombre < pais.nombre;
}

istream &operator>>(istream &is, Pais &pais) {
    double latitud, longitud;
    string nombre, path_bandera;
    is >> latitud >> longitud >> nombre >> path_bandera;
    pais = Pais(nombre, pais.PathBandera()+path_bandera, coordenadas_aPunto(latitud, longitud));

    return is;
}

std::ostream &operator<<(ostream &os, const Pais &pais) {
    std::pair<int, int> coordenadas = punto_aCoordenadas(pais.getPunto());
    os << coordenadas.first << "\t" << coordenadas.second << "\t" << pais.Nombre() << "\t"
       << pais.PathBandera();
    return os;
}
