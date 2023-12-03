#ifndef PRACTICAFINAL_PUNTO_H
#define PRACTICAFINAL_PUNTO_H
#include <fstream>

using namespace std;
/**
 * @file getPunto.h
 * @brief Cabecera de la clase getPunto.
 * @author Iván Rodríguez Chacón
 * @author Javier Lama Jiménez
 */

/**
 * @brief Clase que representa un punto en el plano.
 */
class Punto {
private:
    /**
     * @brief Variable con el tamaño total del mapa
     */
     static int total_filas, total_columnas;
    /**
     * @brief Coordenada x del punto.
     */
    double x;
    /**
     * @brief Coordenada y del punto.
     */
    double y;
public:
    /**
     * @brief Constructor por defecto.
     */
    Punto(double x = 0, double y = 0);

    /**
     * @brief Constructor de copia.
     * @param p getPunto a copiar.
     */
    double getY() const;

    double &getX();
    double &getY();

    /**
     * @brief Devuelve la coordenada y del punto.
     * @return Coordenada y del punto.
     */
    double getX() const;

    int getTotalColumnas() const;
    int getTotalFilas() const;
    bool operator==(const Punto& punto2) const;

    Punto& operator=(const Punto& punto2) = default;
};
/**
 * @brief Función que pasa una latitud y una longitud a un punto de la imagen.
 * @param latitud Coordenada latitud.
 * @param longitud Coordenada longitud.
 * @param totalfilas Total de filas de la imagen.
 * @param totalcolumnas Total de columnas de la imagen.
 * @return getPunto de la imagen al que equivalen las punto.
 */
Punto coordenadas_aPunto(const double &latitud, const double &longitud, int totalfilas, int totalcolumnas);
pair<double,double> punto_aCoordenadas(const Punto &punto, const int &totalfilas, const int &totalcolumnas);
ostream & operator<<(ostream &os, const Punto &punto);
istream & operator>>(istream &is, Punto &punto);

#endif
