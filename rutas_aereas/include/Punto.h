#ifndef PRACTICAFINAL_PUNTO_H
#define PRACTICAFINAL_PUNTO_H

#include <fstream>

using namespace std;
/**
 * @file Punto.h
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
     * @brief getter de la coordenada Y.
     * @return Coordenada Y.
     */
    double getY() const;

    /**
     * @brief getter/setter de la coordenada X.
     * @return Coordenada X.
     */
    double &getX();

    /**
     * @brief getter/setter de la coordenada Y.
     * @return Coordenada Y.
     */
    double &getY();

    /**
     * @brief Devuelve la coordenada y del punto.
     * @return Coordenada y del punto.
     */
    double getX() const;

    /**
     * @brief Devuelve el total de columnas del mapa.
     * @return Total de columnas del mapa.
     */
    static int getTotalColumnas() ;

    /**
     * @brief Devuelve el total de filas del mapa.
     * @return Total de filas del mapa.
     */
    static int getTotalFilas() ;

    /**
     * @brief Metodo para modificar el total de filas del mapa.
     */
    static void setTotalFilas(const int &totalFilas);

    /**
     * @brief Metodo para modificar el total de columnas del mapa.
     */
    static void setTotalColumnas(const int &totalColumnas);

    /**
     * @brief Sobrecarga del operador de comparación.
     * @param punto2 Punto con el que se compara.
     * @return True si es igual o False si es diferente
     */
    bool operator==(const Punto &punto2) const;

    /**
     * @brief Sobrecarga del operador de asignación, especificando que se use el de por defecto.
     * @param punto2 Punto que se asigna.
     * @return referencia al punto asignado.
     */
    Punto &operator=(const Punto &punto2) = default;
};

/**
 * @brief Función que pasa una latitud y una longitud a un punto de la imagen.
 * @param latitud Coordenada latitud.
 * @param longitud Coordenada longitud.
 * @param totalfilas Total de filas de la imagen.
 * @param totalcolumnas Total de columnas de la imagen.
 * @return getPunto de la imagen al que equivalen las punto.
 */
Punto
coordenadas_aPunto(const double &latitud, const double &longitud);

/**
 * @brief Pasa de punto a las coordenadas originales
 * @param punto punto a pasar a coordenadas
 * @param totalfilas total de las filas de la imagen
 * @param totalcolumnas total de columnas de la imagen
 * @return pair<double x,double y>
 */
pair<double, double> punto_aCoordenadas(const Punto &punto);

/**
 * @brief Sobrecarga del operador de salida.
 * @param os Flujo de salida.
 * @param punto Punto que se imprime.
 * @return Flujo de salida.
 */
ostream &operator<<(ostream &os, const Punto &punto);

/**
 * @brief Sobrecarga del operador de entrada.
 * @param is Flujo de entrada.
 * @param punto Punto que se lee.
 * @return Flujo de entrada.
 */
istream &operator>>(istream &is, Punto &punto);

#endif
