#ifndef PRACTICAFINAL_ALMACENRUTA_H
#define PRACTICAFINAL_ALMACENRUTA_H

#include <map>
#include <iostream>
#include <fstream>
#include "Ruta.h"
#include "Punto.h"
using namespace std;
/**
 * @brief Clase que almacena todas las rutas de un fichero
 * @file AlmacenRuta.h
 * @author Iván Rodríguez Chacón
 * @author Javier Lama Jiménez
 */

/**
 * @brief Clase que almacena todas las rutas de un fichero
 * @class AlmacenRuta
 */
class AlmacenRuta {
private:
    /**
    * @brief Map con las rutas
    */
    map<string, Ruta> rutas;

public:
    /**
    * @brief Constructor de la clase
    */
    AlmacenRuta() = default;
    /**
     * @brief Constructor a partir de la ruta del fichero
     * @param fileName Nombre de la ruta del fichero de datos
     */
     explicit AlmacenRuta(const char* fileName);
    /**
    * @brief inserta una ruta a el map
    * @param nombre nombre de la ruta a la que pertenece
    * @param ruta objeto ruta a insertar
    */
    void insert(const string& nombre, const Ruta &ruta);

    /**
    * @brief elimina la ruta con el nombre asociado
    * @param nombre nombre de la ruta
    */
    void erase(const string &nombre);

    /**
    * @brief devuelve la ruta asociada al nombre
    * @param nombre nombre de la ruta
    * @return Objeto Ruta
    */
    Ruta getRuta(const string &nombre);

    /**
     * @brief Sobrecarga del operador de salida
     * @param is Flujo de entrada.
     * @param almacenRuta Objeto donde alamcenar los datos.
     * @return Referencia al flujo de entrada para permitir la concatenación.
     */
    friend istream &operator>>(std::istream &is, AlmacenRuta &almacenRuta);


    /**
     * @brief Clase iterador
     */
    class iterator {
    private:
        /**
         * @brief iterador map<string,Ruta>
         */
        map<string, Ruta>::iterator it;

    public:
        /**
         * @brief Sobrecarga del operador ++
         * @return iterador +1
         */
        iterator &operator++() {
           ++it;
           return *this;
        }
        /**
         * @brief Sobrecarga el operador --
         * @return Iterador -1
         */
        iterator &operator--() {
           --it;
           return *this;
        }
        /**
         * @brief Sobrecarga operador de igualdad ==
         * @param i Iterador a comparar
         * @return True si es igual
         */
        bool operator==(const iterator &i) { return i.it == it; }
        /**
        * @brief Sobrecarga operador de igualdad !=
        * @param i Iterador a comparar
        * @return False si es igual
        */
        bool operator!=(const iterator &i) { return i.it != it; }
        /**
         * @brief Sobrecarga operador de puntero *
         * @return Devuelve puntero del iterador
         */
        Ruta &operator*() {return it->second;}

        friend class AlmacenRuta;
    };
    /**
     * @brief Clase iterador constante
     */
    class const_iterator {
    private:
        /**
         * @brief const_iterator de map<string,Ruta>
         */
        map<string, Ruta>::const_iterator it;

    public:
        /**
         * @brief Constructor de const_iterator
         * @param iterator iterador
         */
        const_iterator(const std::map<string, Ruta>::const_iterator &iterator) : it(iterator) {}
        /**
         * @brief Sobrecarga del operador ++
         * @return iterador +1
         */
        const_iterator &operator++() {
           ++it;
           return *this;
        }
        /**
         * @brief Sobrecarga el operador --
         * @return Iterador -1
         */
        const_iterator &operator--() {
           --it;
           return *this;
        }
        /**
        * @brief Sobrecarga operador de igualdad ==
        * @param i Iterador a comparar
        * @return True si es igual
        */
        bool operator==(const const_iterator &i) const { return i.it == it; }
        /**
        * @brief Sobrecarga operador de igualdad !=
        * @param i Iterador a comparar
        * @return False si es igual
        */
        bool operator!=(const const_iterator &i) const { return i.it != it; }
        /**
         * @brief Sobrecarga operador de puntero *
         * @return Devuelve puntero del iterador
         */
        const Ruta &operator*() const { return it->second; }
        /**
         * @brief Devuelve nombre de la ruta
         * @return nombre de la ruta
         */
        const string &getNombreRuta() const { return it->first; }
        /**
         * @brief Devuelve la ruta
         * @return Ruta del iterador
         */
        const Ruta &getRuta() const{return it->second;}

        friend class AlmacenRuta;
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
     * @brief Sobrecarga del operador []
     * @param nombre nombre de la ruta
     * @return Ruta con el nombre
     */
    Ruta &operator[](const string &nombre);
    /**
     * @brief Sobrecarga constante del operador []
     * @param nombre nombre de la ruta
     * @return Ruta con el nombre
     */
    const Ruta &operator[](const string &nombre) const;
    /**
     * @brief Método que obtiene el tamaño del map<string,Ruta>
     * @return tamaño del map<string,Ruta>
     */
    int size() const;
    /**
     * @brief Metodo cbegin
     * @return el iterador al inicio del map sin errores
     */
    const_iterator cbegin() const;
    /**
     * @brief Metodo cend
     * @return El iterador al final del map sin errores
     */
    const_iterator cend() const;


};
/**
 * @brief Operador de salida
 * @param os buffer de salida
 * @param almacenRuta Objeto
 * @return buffer de datos
 */
ostream &operator<<(ostream &os, const AlmacenRuta &almacenRuta);



#endif //PRACTICAFINAL_ALMACENRUTA_H
