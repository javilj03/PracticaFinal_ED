#ifndef PRACTICAFINAL_ALMACENRUTA_H
#define PRACTICAFINAL_ALMACENRUTA_H

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
    AlmacenRuta() = default;
    /**
     * @brief Constructor a partir de la ruta del fichero
     * @param ruta FileName de la ruta del fichero de datos
     */
     AlmacenRuta(const char* fileName);
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

    friend istream &operator>>(std::istream &is, AlmacenRuta &almacenRuta);

    friend ostream &operator<<(std::ostream &os, const AlmacenRuta &almacenRuta);

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
        friend class const_iterator;
    };
    class const_iterator {
    private:
        std::map<std::string, Ruta>::const_iterator it;

    public:
        const_iterator(const std::map<std::string, Ruta>::const_iterator &iterator) : it(iterator) {}

        const_iterator &operator++() {
           ++it;
           return *this;
        }

        const_iterator &operator--() {
           --it;
           return *this;
        }

        bool operator==(const const_iterator &i) const { return i.it == it; }

        bool operator!=(const const_iterator &i) const { return i.it != it; }

        const Ruta &operator*() const { return it->second; }

        const string &getNombreRuta() const { return it->first; }
        const Ruta &getRuta() const{return it->second;}

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





#endif //PRACTICAFINAL_ALMACENRUTA_H
