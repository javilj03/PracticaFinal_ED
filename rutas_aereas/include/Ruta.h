#ifndef PRACTICAFINAL_RUTA_H
#define PRACTICAFINAL_RUTA_H

#include <vector>
#include <string>
#include "Punto.h"

using namespace std;
/**
 * @file Ruta.h Cabecera de la clase Rutas
 * @brief Cabecera de la clase Rutas.
 * @author Iván Rodríguez Chacón
 * @author Javier Lama Jiménez
 */

/**
 * @brief Clase almacena todos los puntos de una Ruta.
 */

class Ruta {

private:

    /**
    * @brief Lista de todos los puntos que recorre
    */
    vector<Punto> puntos;

public:
    /**
    * @brief Constructor de la clase
    */
    Ruta() = default;
    /**
     * @brief Devuelve el tamaño del vector
     * @return Numero del tamaño del vector
     */
     int size() const;
    /**
    * @brief Inserta un nuevo punto
    * @param punto Objeto punto a insertar
    */
    void insert(const Punto &punto);
    /**
     * @brief Inserta un nuevo punto
     * @param pos posicion del punto a insertar
     * @param punto punto a insertar
     */
    void insert(const int &pos,const Punto &punto);
    /**
    * @brief Elimina un punto de la ruta
    * @param punto Objeto punto a eliminar
    */
    void erase(const Punto &punto);
    /**
     * @brief Sobrecarga de operador []
     * @param i indice del punto.
     * @return Referencia del punto en indice indicado
     */
    Punto & operator[](const int &i);
    /**
     * @brief Sobrecarga constante del operador []
     * @param i indice del punto
     * @return Refercia del punto en indice indicado
     */
    const Punto & operator[](const int &i )const;

    /**
    * @brief Obtiene el vector con todos los puntos de la ruta
    * @return vector<getPunto>
    */
    vector<Punto> getPuntos();
    /**
     * @brief Clase iterador
     */
    class iterator {
    private:
        /**
         * @brief iterador de vector<Punto>
         */
        vector<Punto>::iterator it;

    public:
        /**
         * @brief sobrecarga del operador ++
         * @return devuelve puntero iterador
         */
        iterator &operator++() {
           ++it;
           return *this;
        }
        /**
        * @brief sobrecarga del operador --
        * @return devuelve puntero iterador
        */
        iterator &operator--() {
           --it;
           return *this;
        }
        /**
        * @brief sobrecarga del operador ==
        * @param i iterador a igualar contenido
        * @return True si es igual
        */
        bool operator==(const iterator &i) { return i.it == it; }
        /**
        * @brief sobrecarga del operador !=
        * @param i iterador a igualar contenido
        * @return True si no es igual
        */
        bool operator!=(const iterator &i) { return i.it != it; }
        /**
         * @brief Sobrecarga
         * @return Devuelve puntero
         */
        Punto &operator*() { return *it; }
        friend class Ruta;
    };

   /**
   * @brief Inicializa un Iterator al comienzo de la ruta
   * */
    iterator begin();

   /**
   * @brief Inicializa un Iterator al final de la ruta
   * */
    iterator end();



    /**
     * @brief Elimina un punto de la ruta
     * @param it Objeto punto a eliminar
     */
    void erase(iterator it);
    /**
     * @brief Sobrecarga del operador de entrada
     * @param is istream
     * @param ruta ruta a insertar
     * @return devuelve istream
     */
    friend istream &operator>>(std::istream &is, Ruta &ruta);
};
/**
 * @brief Sobrecarga del operador de salida
 * @param os ostream
 * @param ruta ruta a mostrar
 * @return flujo de salida
 */
ostream &operator<<(std::ostream &os, const Ruta &ruta);



#endif //PRACTICAFINAL_RUTA_H
