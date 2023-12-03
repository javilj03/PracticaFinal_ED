//
// Created by ivanf on 04/11/2023.
//

#ifndef PRACTICAFINAL_IMAGEN_H
#define PRACTICAFINAL_IMAGEN_H

#include <Pixel.h>
#include <imagenES.h>
#include <iostream>
#include <cmath>
/**
 * @file Imagen.h
 * @brief Este fichero contiene la cabecera de la clase Imagen y el enum Tipo_Pegado.
 * @author Iván Rodríguez Chacón
 */

/**
* @brief Enum de los tipos de pegado.
* @see PutImagen
*/
enum Tipo_Pegado {
    OPACO, BLENDING
};

/**
 * @brief Clase Imagen que representa una Imagen de tipo PPM y (opcionalmente) su máscara de tipo PGM.
 */
class Imagen {
private:
    /**
     * @brief Puntero a puntero de Pixel que apunta a la Imagen (Se trata de una matriz).
     */
    Pixel **datos = nullptr;
    /**
     * @brief Puntero a puntero de unsigned char que apunta a la máscara de la Imagen (Se trata de una matriz). Se pone a parte de los pixeles para ahorrar memoria en caso de que no se use máscara.
     */
    unsigned char **mascara = nullptr;
    /**
     * @brief Número de filas de la Imagen.
     */
    int filas;
    /**
     * @brief Número de columnas de la Imagen.
     */
    int columnas;

    /**
     * @brief Función que copia los valores de los atributos de un objeto de la clase en otro de la misma clase.
     * @param im Imagen a copiar.
     */
    void copiar(const Imagen &im);

    /**
     * @brief Método auxiliar para el destructor que elimina la memoria dinámica reservada por las imágenes.
     */
    void liberar();

    /**
     * @brief Función que asigna los datos de la clase.
     * @param filas Filas de la Imagen.
     * @param columnas Columnas de la Imagen.
     * @param buffer Valores a insertar en la Imagen (opcional).
     */
    void asignarMemoria(const int &filas, const int &columnas, Pixel *buffer = nullptr);

    /**
     * @brief Método que lee una máscara de disco y la almacena en mascara.
     * @param nombre Nombre del archivo de la máscara en el disco.
     */
    void LeerMascara(const char nombre[]);

public:
    /**
     * @brief Constructor por defecto de la clase.
     * @param filas Filas de la Imagen.
     * @param columnas Columnas de la Imagen.
     * @pre filas y  columnas deben ser mayores que 0 para asignar espacio en memoria a datos.
     * @post Asigna espacio en memoria para datos pero no inicializa sus valores.
     */
    Imagen(const int &filas = 0, const int &columnas = 0);

    /**
     * @brief Constructor de copia de la clase.
     * @param im Imagen a copiar.
     */
    Imagen(const Imagen &im);

    /**
     * @brief Constructor de la clase que lee una Imagen de disco y asigna espacio en memoria para datos y mascara e inicializa sus valores de los ficheros.
     * @param nombre Nombre del archivo de disco.
     * @param nombre_mascara Nombre del archivo de disco de la máscara (opcional).
     * @pre nombre_mascara debe ser un archivo de tipo PGM.
     */
    Imagen(const char nombre[], const char *nombre_mascara = nullptr);

    /**
     * @brief Destructor de la clase.
     */
    ~Imagen();

    /**
     * @brief Sobrecarga del operador de asignación.
     * @param im Imagen a copiar.
     * @return This, para poder concatenar.
     */
    Imagen &operator=(const Imagen &im);

    /**
     * @brief Método que devuelve el número de filas de la Imagen.
     * @return Número de filas de la Imagen como una referencia a un entero constante.
     */
    const int &Filas() const;

    /**
     * @brief Método que devuelve el número de columnas de la Imagen.
     * @return Número de columnas de la Imagen como una referencia a un entero constante.
     */
    const int &Columnas() const;

    /**
     * @brief Método que escribe una Imagen en disco.
     * @param nombre Nombre del archivo de disco donde guardar la Imagen.
     */
    void EscribirImagen(const char nombre[]) const;

    /**
     * @brief Método que lee una Imagen de disco y la almacena en datos y mascara.
     * @param nombre Nombre del archivo de disco.
     * @param nombre_mascara Nombre del archivo de disco de la máscara (opcional).
     */
    void LeerImagen(const char nombre[], const char *nombre_mascara = nullptr);

    /**
     * @brief Método que pega una Imagen.
     * @param i Fila donde se comienza a pegar.
     * @param j Columna donde se comienza a pegar.
     * @param im Imagen a pegar.
     * @param tipo Tipo de pegado a realizar.
     * @see Tipo_Pegado
     * @pre La Imagen a pegar debe tener asignada su máscara.
     */
    void PutImagen(const int &i, const int &j, const Imagen &im, const Tipo_Pegado &tipo);

    /**
     * @brief Método que devuelve el valor de un píxel de la Imagen como una referencia de Pixel.
     * @param i Fila del píxel.
     * @param j Columna del píxel.
     * @return Valor del píxel como una referencia a un Pixel.
     */
    Pixel &operator()(const int &i, const int &j);

    /**
     * @brief Método que devuelve el valor de un píxel de la Imagen como una referencia constante de Pixel.
     * @param i Fila del píxel.
     * @param j Columna del píxel.
     * @return Valor del píxel como una referencia constante a un Pixel.
     */
    const Pixel &operator()(const int &i, const int &j) const;

};

Imagen Rota(const Imagen &Io, double angulo);

#endif
