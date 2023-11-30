#include "Pais.h"

/**
 * @file Pais.cpp
 * @brief Implementación de la clase Pais.
 */

Pais::Pais(const char *nombre, const Punto &coordenadas, const char *path_bandera) {
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

const Punto &Pais::Coordenadas() const {
    return coordenadas;
}

Punto &Pais::Coordenadas() {
    return coordenadas;
}


Imagen &Pais::Bandera() {
    if (this->bandera.Filas() == 0 || this->bandera.Columnas() == 0)
        this->bandera = Imagen(this->path_bandera);

    return this->bandera;
}

void Pais::asignar(const char *nombre, const char *path_bandera, const Punto &coordenadas) {
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
    delete[] this->nombre;
    delete[] this->path_bandera;
}

std::istream &operator>>(std::istream &is, Pais &pais) {
    double latitud, longitud;
    std::string nombre, path_bandera;

    is >> latitud >> longitud >> nombre >> path_bandera;
    pais = Pais(nombre.c_str(), coordenadas_aPunto(latitud,longitud,768,1536), path_bandera.c_str());

    return is;
}

std::ostream &operator<<(ostream &os, const Pais& pais) {
    pair<double,double> coordendas=punto_aCoordenadas(pais.Coordenadas(),768,1536);
    os<<coordendas.first<<" "<<coordendas.second<<" "<<pais.Nombre()<<" "<<pais.PathBandera()<<endl;
    return os;
}
