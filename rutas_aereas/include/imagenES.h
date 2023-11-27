/**
  * @file imagenES.h
  * @brief Fichero cabecera para la E/S de imágenes. Permite la E/S de archivos de tipos PGM,PPM.
  */

#ifndef IMAGEN_ES_H_
#define IMAGEN_ES_H_

/**
  * @brief Tipo de Imagen
  *
  * Declara una serie de constantes para representar los distintos tipos
  * de imágenes que se pueden manejar.
  *
  * @see LeerTipoImagen
  */
enum TipoImagen {
    IMG_DESCONOCIDO, ///< Tipo de Imagen desconocido
    IMG_PGM,         ///< Imagen tipo PGM
    IMG_PPM          ///< Imagen tipo PPM
};


/**
  * @brief Consulta el tipo de Imagen del archivo y sus dimensiones
  *
  * @param nombre indica el nombre del archivo de disco a consultar
  * @param filas Parámetro de salida con las filas de la Imagen.
  * @param columnas Parámetro de salida con las columnas de la Imagen.
  * @return Devuelve el tipo de la Imagen en el archivo
  *
  * @see TipoImagen
  */
TipoImagen LeerTipoImagen(const char nombre[], int &filas, int &columnas);

/**
  * @brief Lee una Imagen de tipo PPM sobre memoria reservada
  *
  * @param nombre nombre del archivo a leer
  * @param filas Parámetro de salida con las filas de la Imagen.
  * @param columnas Parámetro de salida con las columnas de la Imagen.
  * @param buffer Zona de memoria para obtener el valor de cada uno de los píxeles
  * como tripletas consecutivas en formato RGB (RGBRGBRGB...) por filas
  * desde la esquina superior izqda a la inferior drcha. 
  * @return si ha  tenido éxito en la lectura
  * @pre buffer debe ser una zona de memoria suficientemente grande como para
  * almacenar @a filas x @a columnas x 3  * bytes de datos de la Imagen.
  */
bool LeerImagenPPM(const char nombre[], int &filas, int &columnas, unsigned char buffer[]);

/**
  * @brief Escribe una Imagen de tipo PPM
  *
  * @param nombre nombre del archivo a escribir
  * @param datos punteros a los @a f x @a c x 3 bytes que corresponden a los valores
  *    de los píxeles de la Imagen en formato RGB.
  * @param f filas de la Imagen
  * @param c columnas de la Imagen
  * @retval true si ha tenido éxito en la escritura.
  * @retval false si se ha producido algún error en la escritura.
  */
bool EscribirImagenPPM(const char nombre[], const unsigned char datos[], int f, int c);

/**
  * @brief Lee una Imagen de tipo PGM sobre memoria reservada
  *
  * @param nombre nombre del archivo a leer
  * @param filas Parámetro de salida con las filas de la Imagen.
  * @param columnas Parámetro de salida con las columnas de la Imagen.
  * @param buffer Zona de memoria para obtener el valor de cada uno de los píxeles
  * como un valor de gris desde la esquina superior izqda a la inferior drcha. 
  * @return si ha  tenido éxito en la lectura
  * @pre buffer debe ser una zona de memoria suficientemente grande como para
  * almacenar @a filas x @a columnas bytes de datos de la Imagen.
  */
bool LeerImagenPGM(const char nombre[], int &filas, int &columnas, unsigned char buffer[]);

/**
  * @brief Escribe una Imagen de tipo PGM
  *
  * @param nombre nombre del archivo a escribir
  * @param datos punteros a los @a f x @a c bytes que corresponden a los valores
  *    de los píxeles de la Imagen de grises.
  * @param f filas de la Imagen
  * @param c columnas de la Imagen
  * @retval true si ha tenido éxito en la escritura.
  * @retval false si se ha producido algún error en la escritura.
  */
bool EscribirImagenPGM(const char nombre[], const unsigned char datos[], int f, int c);

#endif