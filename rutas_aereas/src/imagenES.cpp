#include <fstream>
#include <string>
#include <imagenES.h>

/**
  * @file imagenES.cpp
  * @brief Fichero con definiciones para la E/S de imágenes. Permite la E/S de archivos de tipo PGM,PPM.
  */

using namespace std;

/**
 * @brief Leer el tipo de la imagen.
 * @param f entrada de flujo.
 * @return El tipo de imagen.
 * @see TipoImagen
 */
TipoImagen LeerTipo(ifstream &f) {
    char c1, c2;
    TipoImagen res = IMG_DESCONOCIDO;

    if (f) {
        c1 = f.get();
        c2 = f.get();
        if (f && c1 == 'P')
            switch (c2) {
                case '5':
                    res = IMG_PGM;
                    break;
                case '6':
                    res = IMG_PPM;
                    break;
                default:
                    res = IMG_DESCONOCIDO;
            }
    }
    return res;
}

// _____________________________________________________________________________
/**
 * @brief Leer el tipo de la imagen.
 * @param nombre nombre del archivo.
 * @return Tipo de la imagen.
 * @see TipoImagen
 */
TipoImagen LeerTipoImagen(const char nombre[]) {
    ifstream f(nombre, std::ios::binary);
    return LeerTipo(f);
}


// _____________________________________________________________________________
/**
 * @brief Saltar los comentarios de un archivo.
 * @param f flujo de entrada.
 * @return El siguiente carácter que no es un espacio en blanco.
 */
char SaltarSeparadores(ifstream &f) {
    char c;
    do {
        c = f.get();
    } while (isspace(c));
    f.putback(c);
    return c;
}

// _____________________________________________________________________________
/**
 * @brief Leer la cabecera de una imagen.
 * @param f entrada de flujo.
 * @param filas Filas de la imagen (o más bien donde se guarda este dato ya que esta referenciado).
 * @param columnas Columnas de la imagen (o más bien donde se guarda este dato ya que esta referenciado).
 * @return True si pudo leerla, false en caso contrario.
 */
bool LeerCabecera(ifstream &f, int &filas, int &columnas) {
    int maxvalor;

    while (SaltarSeparadores(f) == '#')
        f.ignore(10000, '\n');

    f >> columnas >> filas >> maxvalor;

    if (/*str &&*/ f && filas > 0 && filas < 5000 && columnas > 0 && columnas < 5000) {
        f.get(); // Saltamos separador
        return true;
    } else return false;
}

// _____________________________________________________________________________
/**
 * @brief Leer el tipo de la imagen.
 * @param nombre nombre del archivo.
 * @param filas Filas de la imagen (o más bien donde se guarda este dato ya que esta referenciado).
 * @param columnas Columnas de la imagen (o más bien donde se guarda este dato ya que esta referenciado).
 * @return Tipo de imagen.
 * @see TipoImagen
 */
TipoImagen LeerTipoImagen(const char nombre[], int &filas, int &columnas) {
    TipoImagen tipo;
    filas = columnas = 0;
    ifstream f(nombre, std::ios::binary);

    tipo = LeerTipo(f);
    if (tipo != IMG_DESCONOCIDO)
        if (!LeerCabecera(f, filas, columnas)) {
            tipo = IMG_DESCONOCIDO;
        }

    return tipo;
}


// _____________________________________________________________________________
/**
 * @brief Leer una imagen de tipo PPM.
 * @param nombre Nombre del archivo.
 * @param filas Filas de la imagen (o más bien donde se guarda este dato ya que esta referenciado).
 * @param columnas Columnas de la imagen (o más bien donde se guarda este dato ya que esta referenciado).
 * @param buffer Buffer donde almacenar la imagen.
 * @return True si tuvo éxito, false en caso contrario.
 */
bool LeerImagenPPM(const char nombre[], int &filas, int &columnas, unsigned char buffer[]) {
    bool exito = false;
    filas = 0;
    columnas = 0;
    ifstream f(nombre, std::ios::binary);


    if (LeerTipo(f) == IMG_PPM)
        if (LeerCabecera(f, filas, columnas))
            if (f.read(reinterpret_cast<char *>(buffer), filas * columnas * 3))
                exito = true;

    f.close();
    return exito;
}


// _____________________________________________________________________________
/**
 * @brief Leer una imagen de tipo PGM.
 * @param nombre Nombre del archivo.
 * @param filas Filas de la imagen (o más bien donde se guarda este dato ya que esta referenciado).
 * @param columnas Columnas de la imagen (o más bien donde se guarda este dato ya que esta referenciado).
 * @param buffer Buffer donde almacenar la imagen.
 * @return True si tuvo éxito, false en caso contrario.
 */
bool LeerImagenPGM(const char nombre[], int &filas, int &columnas, unsigned char buffer[]) {
    bool exito = false;
    filas = 0;
    columnas = 0;
    ifstream f(nombre, std::ios::binary);

    if (LeerTipo(f) == IMG_PGM)
        if (LeerCabecera(f, filas, columnas))
            if (f.read(reinterpret_cast<char *>(buffer), filas * columnas))
                exito = true;

    return exito;
}


// _____________________________________________________________________________
/**
 * @brief Escribir una imagen de tipo PPM.
 * @param nombre Nombre del archivo.
 * @param datos Buffer donde se almacena la imagen.
 * @param filas Filas de la imagen.
 * @param columnas Columnas de la imagen.
 * @return True si tuvo éxito, false en caso contrario.
 */
bool EscribirImagenPPM(const char nombre[], const unsigned char datos[], int filas, int columnas) {
    ofstream f(nombre, std::ios::binary);
    bool res = true;

    if (f) {
        f << "P6" << endl;
        f << columnas << ' ' << filas << endl;
        f << 255 << endl;
        f.write(reinterpret_cast<const char *>(datos), filas * columnas * 3);
        if (!f) res = false;
    }
    return res;
}
// _____________________________________________________________________________
/**
 * @brief Escribir una imagen de tipo PGM.
 * @param nombre Nombre del archivo.
 * @param datos Buffer donde se almacena la imagen.
 * @param filas Filas de la imagen.
 * @param columnas Columnas de la imagen.
 * @return True si tuvo éxito, false en caso contrario.
 */
bool EscribirImagenPGM(const char nombre[], const unsigned char datos[], int filas, int columnas) {
    ofstream f(nombre, std::ios::binary);
    bool res = true;

    if (f) {
        f << "P5" << endl;
        f << columnas << ' ' << filas << endl;
        f << 255 << endl;
        f.write(reinterpret_cast<const char *>(datos), filas * columnas);
        if (!f) res = false;
    }
    return res;
}


/* Fin Fichero: imagenES.cpp */

