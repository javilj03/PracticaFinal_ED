#include "Imagen.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <imagenES.h>
#include <fstream>

using namespace std;
/**
 * @file pruebarotacion.cpp
 * @brief Programa para rotar una imagen PPM.
 */

/**
 * @brief Rota una Imagen.
 * @param Io Imagen de entrada.
 * @param angulo Angulo de rotación.
 * @return La Imagen rotada.
 */
unsigned char** Rota(unsigned char **Io, double angulo, int filas, int columnas) {
    double rads = angulo;
    double coseno = cos(angulo);
    double seno = sin(angulo);
    //Para obtener las dimensiones de la Imagen
    int rcorners[4], ccorners[4];
    int newimgrows, newimgcols;
    double new_row_min, new_col_min, new_row_max, new_col_max;
    double inter, inter1;
    rcorners[0] = 0;
    rcorners[1] = 0;
    ccorners[0] = 0;
    ccorners[2] = 0;
    rcorners[2] = filas - 1;
    rcorners[3] = filas - 1;
    ccorners[1] = filas - 1;
    ccorners[3] = filas - 1;
    new_row_min = 0;
    new_col_min = 0;
    new_row_max = 0;
    new_col_max = 0;
    newimgrows = 0;
    newimgcols = 0;
    for (int count = 0; count < 4; count++) {
        inter = rcorners[count] * coseno + ccorners[count] * seno;

        if (inter < new_row_min)
            new_row_min = inter;
        if (inter > new_row_max)
            new_row_max = inter;
        inter1 = -rcorners[count] * seno + ccorners[count] * coseno;

        if (inter1 < new_col_min)
            new_col_min = inter1;
        if (inter1 > new_col_max)
            new_col_max = inter1;
    }

    newimgrows = (unsigned) ceil((double) new_row_max - new_row_min);
    newimgcols = (unsigned) ceil((double) new_col_max - new_col_min);
    unsigned char **mascara = new unsigned char *[newimgrows];
    mascara[0] = new unsigned char[newimgrows * newimgcols];
    for (int i = 1; i < newimgrows; i++)
        mascara[i] = mascara[i - 1] + newimgcols;

    for (int rows = 0; rows < newimgrows; rows++) {
        for (int cols = 0; cols < newimgcols; cols++) {
            float oldrowcos = ((float) rows + new_row_min) * cos(-rads);
            float oldrowsin = ((float) rows + new_row_min) * sin(-rads);
            float oldcolcos = ((float) cols + new_col_min) * cos(-rads);
            float oldcolsin = ((float) cols + new_col_min) * sin(-rads);
            float old_row = oldrowcos + oldcolsin;
            float old_col = -oldrowsin + oldcolcos;
            old_row = ceil((double) old_row);
            old_col = ceil((double) old_col);
            if ((old_row >= 0) && (old_row < filas) &&
                (old_col >= 0) && (old_col < columnas)) {
                unsigned int fila = (int) old_row;
                unsigned int columna = (int) old_col;
                mascara[rows][cols] = Io[fila][columna];

            } else
                mascara[rows][cols]= 255;
        }
    }
    return mascara;

}


int main(int argc, char *argv[]) {
    if (argc != 4) {
        cout << "Los parametros son :" << endl;
        cout << "1.-La Imagen de entrada" << endl;
        cout << "2.-El angulo de rotación" << endl;
        cout << "3.-El nombre de la Imagen de salida" << endl;
        return 0;
    }
    int filas, columnas;
    ifstream entrada(argv[1]);
    unsigned char** imagen;
    LeerTipoImagen(argv[1], filas, columnas);
    unsigned char *aux = new unsigned char[filas * columnas];
    LeerImagenPGM(argv[1],filas, columnas, aux);
    imagen[0] = aux;
    double angulo = atof(argv[2]);
    angulo = angulo * (M_PI) / 180;
    EscribirImagenPGM(argv[3], aux, filas, columnas);
    unsigned char** salida = Rota(imagen, angulo,filas,columnas);
    EscribirImagenPGM(argv[3], salida[0], filas, columnas);

    //Iout.EscribirImagen(argv[3]);

}  