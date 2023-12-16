#ifndef PRACTICAFINAL_PAIS_H
#define PRACTICAFINAL_PAIS_H

#include <Imagen.h>
#include "Punto.h"
#include <cstring>

/**
 * @file Pais.h Cabecera de la clase Pais
 * @brief Cabecera de la clase Pais.
 * @author Iván Rodríguez Chacón
 * @author Javier Lama Jiménez
 */

/**
 * @brief Clase que representa un pais y nos proporciona información sobre el mismo.
 */
class Pais {
private:
    /**
     * @brief Imagen de la bandera del pais. Esta inicializado a null hasta que se necesite la imagen por primera vez.
     */
    Imagen bandera;
    /**
     * @brief Nombre del pais como un array de carácteres.
     */
    string nombre;
    /**
     * @brief Ruta en el equipo de la bandera del pais como un array de carácteres.
     */
    string path_bandera;

    /**
     * @brief Punto del pais.
     */
    Punto punto;

    /**
     * @brief Función que asigna los valores de los atributos de la clase.
     * @param nombre Array de carácteres que contiene el nombre del pais.
     * @param path_bandera Array de carácteres que contiene la ruta de la bandera del país.
     * @param punto Punto que contiene las punto del país.
     */
    void asignar(const string &nombre, const string &path_bandera, const Punto &punto);

    /**
     * @brief Función que copia los valores de los atributos de un objeto de la clase en otro de la misma clase.
     * @param pais País a copiar.
     */
    void copiar(const Pais &pais);

public:
    /**
     * @brief Constructor por defecto de la clase.
     * @param nombre Nombre del país.
     * @param path_bandera Ruta hacia la bandera del país.
     * @param punto Punto donde se encuentra el país.
     */
     explicit Pais(const string &nombre="", const string &path_bandera="",const Punto &punto = Punto(0,0));

    /**
     * @brief Constructor de copia de la clase.
     * @param pais País a copiar.
     */
    Pais(const Pais &pais);

    /**
     * @brief Sobrecarga del operador de asignación.
     * @param pais País a copiar.
     * @return This, para poder concatenar.
     */
    Pais &operator=(const Pais &pais);

    /**
     * @brief Método constante que devuelve el nombre del país.
     * @return Nombre del país como un puntero a char constante.
     */
    const string &Nombre() const;

    /**
     * @brief Método que devuelve el nombre del país.
     * @return Nombre del país como un puntero a char.
     */
    string &Nombre();

    /**
     * @brief Método constante que devuelve la ruta de la bandera del país.
     * @return Ruta de la bandera del país como un puntero a char constante.
     */
    const string &PathBandera() const;

    /**
     * @brief Método que devuelve la ruta de la bandera del país.
     * @return Ruta de la bandera del país como un puntero a char.
     */
    string &PathBandera();

    /**
     * @brief Método constante que devuelve el punto del país.
     * @return Punto del país como una referencia a getPunto constante.
     */
    const Punto &getPunto() const;

    /**
     * @brief Método que devuelve el punto del país.
     * @return Objeto punto del País.
     */
    Punto &getPunto();

    /**
     * @brief Método que devuelve la Imagen de la bandera del país si ya está cargada en bandera sino lo carga y lo devuelve como una referencia.
     * @return Imagen de la bandera del país como un objeto de la clase Imagen.
     */
    Imagen &Bandera();

    /**
     * @brief Sobrecarga del operador menor que.
     * @param pais País a comparar.
     * @return True si this es menor que Pais, false en caso contrario.
     */
    bool operator<(const Pais &pais) const;
};

/**
 * @brief Sobrecarga del operador de entrada.
 * @param os Entrada del flujo.
 * @param pais País a obtener.
 * @return Referencia al flujo de entrad para poder concatenarlo.
 */
istream &operator>>(std::istream &os, Pais &pais);

/**
 * @brief Sobrecarga del operador de salida.
 * @param os Salida del flujo.
 * @param pais País a mostrar.
 * @return Referencia al flujo de salida para poder concatenarlo.
 */
ostream &operator<<(std::ostream &os, const Pais &pais);


#endif