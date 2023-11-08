#ifndef PRACTICAFINAL_PIXEL_H
#define PRACTICAFINAL_PIXEL_H
/**
 * @file Pixel.h
 * @brief Cabecera de la clase Pixel.
 * @author Iván Rodríguez Chacón
 */

/**
 * @brief Clase Pixel que representa un píxel de las imágenes.
 */
class Pixel {
private:
    /**
     * @brief Componente roja del píxel.
     */
    unsigned char red;
    /**
     * @brief Componente verde del píxel.
     */
    unsigned char green;
    /**
     * @brief Componente azul del píxel.
     */
    unsigned char blue;
public:
    /**
     * @brief Constructor por defecto.
     * @param red Componente roja del píxel.
     * @param green Componente verde del píxel.
     * @param blue Componente azul del píxel.
     */
    Pixel(const unsigned char &red = 0, const unsigned char &green = 0, const unsigned char &blue = 0);

    /**
     * @brief Establece los valores de los componentes del píxel.
     * @param red Componente roja del píxel.
     * @param green Componente verde del píxel.
     * @param blue Componente azul del píxel.
     */
    void set(const unsigned char &red, const unsigned char &green, const unsigned char &blue);

    /**
     * @brief Devuelve una referencia de la componente roja del píxel.
     * @return Componente roja del píxel como un unsigned char referenciado.
     */
    unsigned char &Red();

    /**
     * @brief Devuelve una referencia constante de la componente roja del píxel.
     * @return Componente roja del píxel como un unsigned char constante referenciado.
     */
    const unsigned char &Red() const;

    /**
     * @brief Devuelve una referencia de la componente verde del píxel.
     * @return Componente verde del píxel como un unsigned char referenciado.
     */
    unsigned char &Green();

    /**
     * @brief Devuelve una referencia constante de la componente verde del píxel.
     * @return Componente verde del píxel como un unsigned char constante referenciado.
     */
    const unsigned char &Green() const;

    /**
     * @brief Devuelve una referencia de la componente azul del píxel.
     * @return Componente azul del píxel como un unsigned char referenciado.
     */
    unsigned char &Blue();

    /**
     * @brief Devuelve una referencia constante de la componente azul del píxel.
     * @return Componente azul del píxel como un unsigned char constante referenciado.
     */
    const unsigned char &Blue() const;

    /**
     * @brief Sobrecarga del operador == para comparar un píxel con un entero, esto devuelve true si todas las componentes del píxel son iguales al entero.
     * @param n Entero con el que se compara el píxel.
     * @return True si el píxel es igual al entero, false en caso contrario.
     */
    bool operator==(const int &n) const;

    /**
     * @brief Sobrecarga del operador != para comparar un píxel con un entero, esto devuelve true si todas las componentes del píxel son distintas al entero.
     * @param n Entero con el que se compara el píxel.
     * @return True si el píxel es distinto al entero, false en caso contrario.
     */
    bool operator!=(const int &n) const;

    /**
     * @brief Calcula la media de dos píxeles.
     * @param rgb2 Píxel con el que se calcula la media.
     * @return Píxel resultante de la media.
     */
    Pixel media(const Pixel &rgb2) const;
};


#endif
