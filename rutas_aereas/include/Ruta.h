#ifndef PRACTICAFINAL_RUTA_H
#define PRACTICAFINAL_RUTA_H

#include <vector>
#include <string>
#include "Punto.h"

using namespace std;
/**
 * @file Rutas.h Cabecera de la clase Rutas
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
    /**
    * @brief Nombre de la ruta
    */
public:
    /**
    * @brief Constructor de la clase
    */
    Ruta();

    /**
    * @brief Inserta un nuevo punto
    * @param punto Objeto punto a insertar
    */
    void insert(Punto punto);

    /**
    * @brief Elimina un punto de la ruta
    * @param punto Objeto punto a eliminar
    */
    void erase(Punto punto);

    /**
    * @brief Modifica el codigo de la ruta
    * @param code string del nuevo codigo de la ruta
    */
    void setCode(string code);

    /**
    * @brief Obtiene el vector con todos los puntos de la ruta
    * @return vector<getPunto>
    */
    vector<Punto> getPuntos();

    class iterator {
    private:
        vector<Punto>::iterator it;

    public:
        iterator &operator++() {
           ++it;
           return *this;
        }

        iterator &operator--() {
           --it;
           return *this;
        }

        bool operator==(const iterator &i) { return i.it == it; }

        bool operator!=(const iterator &i) { return i.it != it; }

        Punto &operator*() { return *it; }
        friend class Ruta;
    };

   /**
   * @brief Inicializa un Iterator al comienzo de la ruta
   * */
    iterator begin() {
       iterator i;
       i.it = puntos.begin();
       return i;
    }

   /**
   * @brief Inicializa un Iterator al final de la ruta
   * */
    iterator end() {
       iterator i;
       i.it = puntos.end();
       return i;
    }

    /**
     * @brief Elimina un punto de la ruta
     * @param iterator Objeto punto a eliminar
     */
    void erase(iterator it);
    friend istream &operator>>(std::istream &is, Ruta &ruta);
    friend ostream &operator<<(std::ostream &os, const Ruta &ruta);
};





#endif //PRACTICAFINAL_RUTA_H
