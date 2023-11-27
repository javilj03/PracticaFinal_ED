#ifndef PRACTICAFINAL_ALMACENRUTAS_H
#define PRACTICAFINAL_ALMACENRUTAS_H

#include <map>
#include "Ruta.h"
#include "Punto.h"

/**
 * @brief Clase que almacena todas las rutas de un fichero
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
    AlmacenRuta();

    /**
    * @brief inserta una ruta a el map
    * @param nombre nombre de la ruta a la que pertenece
    * @param ruta objeto ruta a insertar
    */
    void insert(string nombre, Ruta &ruta);

    /**
    * @brief elimina la ruta con el nombre asociado
    * @param nombre nombre de la ruta
    */
    void erase(string nombre);

    /**
    * @brief devuelve la ruta asociada al nombre
    * @param nombre nombre de la ruta
    * @return Objeto Ruta
    */
    Ruta getRuta(string nombre);

    class iterator {
    private:
        map<string, Ruta>::iterator it;

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

        Ruta &operator*() {return it->second;}

        friend class AlmacenRuta;
    };

    /**
    * @brief Inicializa un Iterator al comienzo de la ruta
    * */
    iterator begin() {
       iterator i;
       i.it = rutas.begin();
       return i;
    }

    /**
    * @brief Inicializa un Iterator al final de la ruta
    * */
    iterator end() {
       iterator i;
       i.it = rutas.end();
       return i;
    }
};


istream &operator>>(std::istream &os, Ruta &ruta);

istream &operator<<(std::istream &os, Ruta &ruta);


#endif //PRACTICAFINAL_ALMACENRUTAS_H
