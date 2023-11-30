#ifndef PRACTICAFINAL_PUNTO_H
#define PRACTICAFINAL_PUNTO_H
#include <fstream>

using namespace std;
/**
 * @file Punto.h
 * @brief Cabecera de la clase Punto.
 * @author Iván Rodríguez Chacón
 * @author Javier Lama Jiménez
 */

/**
 * @brief Clase que representa un punto en el plano.
 */
class Punto {
private:
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
     * @param p Punto a copiar.
     */
    double getY() const;

    double &getX();
    double &getY();

    /**
     * @brief Devuelve la coordenada y del punto.
     * @return Coordenada y del punto.
     */
    double getX() const;

    bool operator==(const Punto& punto2) const;
};
/**
 * @brief Función que pasa una latitud y una longitud a un punto de la imagen.
 * @param latitud Coordenada latitud.
 * @param longitud Coordenada longitud.
 * @param totalfilas Total de filas de la imagen.
 * @param totalcolumnas Total de columnas de la imagen.
 * @return Punto de la imagen al que equivalen las coordenadas.
 */
Punto coordenadas_aPunto(const double &latitud, const double &longitud, int totalfilas, int totalcolumnas);
pair<double,double> punto_aCoordenadas(const Punto &punto, const int &totalfilas, const int &totalcolumnas);
ostream & operator<<(ostream &os, const Punto &punto);
istream & operator>>(istream &is, Punto &punto);

#endif
