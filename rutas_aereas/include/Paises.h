#ifndef PRACTICAFINAL_PAISES_H
#define PRACTICAFINAL_PAISES_H

#include <set>
#include <iostream>
#include <Pais.h>
#include <iomanip>
/**
 * @file Paises.h Cabecera de la clase Paises
 * @brief Clase que almacena todos los paises de un fichero
 * @see Pais
 * @author Iván Rodríguez Chacón
 */
class Paises {
private:
    /**
     * @brief Cabecera del fichero.
     */
    const static string CABECERA;
    /**
     * @brief Set que almacena todos los paises ordenados por orden alfabético.
     */
    set<Pais> datos;

    /**
     * @brief Función que inserta los países de un fichero en el set.
     * @param fileName Nombre del fichero.
     */
    void insertar(const char *fileName);

public:
    /**
     * @brief Constructor a partir de un fichero.
     * @param fileName Ruta del fichero a leer.
     */
    Paises(const char *fileName);

    /**
     * @brief Clase iteradora que permite recorrer el set de paises.
     */
    class Iterator {
    private:
        /**
         * @brief Iterador del set de paises.
         */
        set<Pais>::iterator iterador;
    public:
        /**
         * @brief Constructor por defecto.
         */
        Iterator();
        /**
         * @brief Constructor de copia.
         * @param other Iterador a copiar.
         */
        Iterator(const Iterator &other);

        /**
         * @brief Constructor a partir de un iterador del set de paises.
         * @param it Iterador a copiar en this.
         */
        Iterator(const set<Pais>::iterator &it);

        /**
         * @brief Operador de preincremento.
         * @return Siguiente posición del iterador (aumenta el iterador interno).
         */
        Iterator &operator++();
        /**
         * @brief Operador de postincremento.
         * @return Siguiente posición del iterador (aumenta el iterador interno).
         */
        Iterator &operator++(int);

        /**
         * @brief Operador de desreferenciación.
         * @return El Pais apuntado por el Iterador.
         */
        Pais operator*() const;

        /**
         * @brief Operador de comparación.
         * @param it2 Iterador a comparar.
         * @return True si son distintos, false en caso contrario.
         */
        bool operator!=(Iterator it2) const;
    };
    /**
     * @brief Clase iteradora constante que permite recorrer el set de paises.
     */
    class const_Iterator {
    private:
        /**
         * @brief Iterador constante del set de paises.
         */
        set<Pais>::const_iterator iterador;
    public:
        /**
         * @brief Constructor a partir de un iterador constante del set de paises.
         */
        const_Iterator(const set<Pais>::const_iterator &it);
        /**
         * @brief Operador de preincremento.
         * @return Siguiente posición del iterador.
         */
        const_Iterator &operator++();
        /**
         * @brief Operador de postincremento.
         * @return Siguiente posición del iterador.
         */
        const_Iterator &operator++(int);
        /**
         * @brief Operador de desreferenciación.
         * @return El Pais apuntado por el Iterador.
         */
        Pais operator*() const;
        /**
         * @brief Operador de comparación.
         * @param it2 Iterador a comparar.
         * @return True si son distintos, false en caso contrario.
         */
        bool operator!=(const_Iterator it2) const;
    };
    /**
     * @brief Funcion que devuelve un iterador constante al inicio del set .
     * @return const_Iterator con el inicio del set.
     */
    const_Iterator begin() const;
    /**
     * @brief Funcion que devuelve un iterador constante al final del set .
     * @return const_Iterator con el final del set.
     */
    const_Iterator end() const;
    /**
     * @brief Funcion que devuelve un iterador al inicio del set .
     * @return Iterator con el inicio del set.
     */
    Iterator begin();
    /**
     * @brief Funcion que devuelve un iterador al final del set .
     * @return Iterator con el final del set.
     */
    Iterator end();

    /**
     * @brief Funcion que indica si el set esta vacio.
     * @return True en caso de que este vacio false en caso contrario.
     */
    bool empty() const;
    /**
     * @brief Funcion que inserta un pais en el set.
     * @param pais Pais a insertar
     * @return True si fue posible, false en caso contrario.
     */
    bool insert(Pais pais);
    /**
     * @brief Funcion que inserta un conjunto de paises en el set.
     * @param begin Iterador del comienzo.
     * @param end Iterador del final.
     */
    void insert(const Paises::Iterator &begin, const Paises::Iterator &end);
    /**
     * @brief Funcion que elimina un pais del set.
     * @param pais Pais a eliminar.
     */
    void erase(const Pais &pais);
    /**
     * @brief Funcion que elimina un pais del set.
     * @param it Iterador del pais a eliminar.
     */
    void erase(const Paises::Iterator &it);
    /**
     * @brief Funcion que vacía el set.
     */
    void clear();
    /**
     * @brief Funcion que busca un pais en el set.
     * @param pais Pais a buscar.
     * @return un iterador a la posicion del pais en el set. En caso de no encontrarse devuelve end().
     */
    Paises::Iterator find(const Pais &pais) const;
    /**
     * @brief Funcion que guarda this en un fichero.
     * @param fileName ruta dle fichero donde se guardarán los datos.
     */
    void save(const char *fileName) const;
};
/**
 * @brief Sobrecarga del operador de salida.
 * @param os Flujo de salida.
 * @param paises Paises a imprimir.
 * @return Flujo de salida.
 */
ostream &operator<<(ostream &os, const Paises &paises);
/**
 * @brief Sobrecarga del operador de entrada.
 * @param is Flujo de entrada.
 * @param paises Paises a leer.
 * @return Flujo de entrada.
 */
istream &operator>>(istream &is, Paises &paises);

#endif //PRACTICAFINAL_PAISES_H
