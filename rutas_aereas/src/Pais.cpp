#include "Pais.h"

/**
 * @file Pais.cpp
 * @brief Implementación de la clase Pais.
 */
int Pais::total_filas=0;
int Pais::total_columnas=0;
Pais::Pais(const char *nombre, const Punto &punto, const char *path_bandera, const int &total_filas, const int &total_columnas) {

    Pais::total_filas = total_filas;
    Pais::total_columnas = total_columnas;
    this->asignar(nombre, path_bandera, punto);
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
    return punto;
}


Imagen &Pais::Bandera() {
    if (this->bandera.Filas() == 0 || this->bandera.Columnas() == 0)
        this->bandera = Imagen(this->path_bandera);

    return this->bandera;
}

void Pais::asignar(const char *nombre, const char *path_bandera, const Punto &punto) {
    this->nombre = strdup(nombre);
    this->path_bandera = strdup(path_bandera);
    this->punto = punto;
}

void Pais::copiar(const Pais &pais) {
    this->asignar(pais.nombre, pais.path_bandera, pais.punto);
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

std::istream &operator>>(std::istream &is, Pais &pais) {
    double latitud, longitud;
    std::string nombre, path_bandera;
    is >> latitud >> longitud >> nombre >> path_bandera;
    pais = Pais(nombre.c_str(), coordenadas_aPunto(latitud, longitud, pais.Tamano_mapa().first,pais.Tamano_mapa().second), path_bandera.c_str());

    return is;
}
pair<int,int> Pais::Tamano_mapa() const {
    return {total_filas,total_columnas};
}

std::ostream &operator<<(ostream &os, const Pais &pais) {
    std::pair<int, int> coordenadas = punto_aCoordenadas(pais.getPunto(),pais.Tamano_mapa().first, pais.Tamano_mapa().second);
    os << coordenadas.first << "\t" << coordenadas.second << "\t" << pais.Nombre() << "\t"
       << pais.PathBandera();
    return os;
}
