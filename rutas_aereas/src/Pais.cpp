#include "Pais.h"

/**
 * @file Pais.cpp
 * @brief Implementación de la clase Pais.
 */

Pais::Pais(const char *nombre, const pair<double, double> &coordenadas, const char *path_bandera) {
    this->asignar(nombre, path_bandera, coordenadas);
}

Pais::Pais(const Pais &pais) {
    this->copiar(pais);
}

Pais::~Pais() {
    this->liberar();
}

Pais &Pais::operator=(const Pais &pais) {
    if (this != &pais) {
        this->liberar();
        this->copiar(pais);
    }
    return *this;
}

const char *Pais::Nombre() const {
    return this->nombre;
}

char *Pais::Nombre() {
    return this->nombre;
}

const char *Pais::PathBandera() const {
    return this->path_bandera;
}

char *Pais::PathBandera() {
    return this->path_bandera;
}

const Punto &Pais::getPunto() const {
    return this->punto;
}

Punto &Pais::getPunto() {
    if (this->punto.getX() < 0 && this->punto.getY() < 0)
        this->punto = coordenadas_aPunto(this->coordenadas.first, this->coordenadas.second, 768, 1536);

    return punto;
}


Imagen &Pais::Bandera() {
    if (this->bandera.Filas() == 0 || this->bandera.Columnas() == 0)
        this->bandera = Imagen(this->path_bandera);

    return this->bandera;
}

void Pais::asignar(const char *nombre, const char *path_bandera, const pair<double, double> &coordenadas) {
    this->nombre = strdup(nombre);
    this->path_bandera = strdup(path_bandera);
    this->coordenadas = coordenadas;
}

void Pais::copiar(const Pais &pais) {
    this->asignar(pais.nombre, pais.path_bandera, pais.coordenadas);
    if (pais.bandera.Filas() != 0 && pais.bandera.Columnas() != 0)
        this->bandera = pais.bandera;
}

void Pais::liberar() {
    if(this->nombre!= nullptr)
        free(this->nombre);
    if(this->path_bandera!= nullptr)
        free(this->path_bandera);
}

bool Pais::operator<(const Pais &pais) const {
    return strcmp(this->nombre, pais.nombre) < 0;
}


const pair<double, double> &Pais::Coordenadas() const {
    return this->coordenadas;
}

pair<double, double> &Pais::Coordenadas() {
    return this->coordenadas;
}

std::istream &operator>>(std::istream &is, Pais &pais) {
    double latitud, longitud;
    std::string nombre, path_bandera;

    is >> latitud >> longitud >> nombre >> path_bandera;
    pais = Pais(nombre.c_str(), {latitud, longitud}, path_bandera.c_str());

    return is;
}


std::ostream &operator<<(ostream &os, const Pais &pais) {

    os << pais.Coordenadas().first << "\t" << pais.Coordenadas().second << "\t" << pais.Nombre() << "\t"
       << pais.PathBandera();
    return os;
}
