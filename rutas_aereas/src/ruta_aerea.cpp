#include <iostream>
#include "AlmacenRuta.h"
#include "Imagen.h"
#include <Paises.h>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {

    if(argc != 7) {
        cerr
                << "Se debe usar <Datos de paises> <mapa global> <directorio banderas> <almacén rutas> <avión> <mascara avión>"
                << endl;
        exit(1);
    }
    Paises paises(argv[1], argv[3]);
    Imagen mapa(argv[2]);

    AlmacenRuta almacenRuta(argv[4]);
    Imagen avion(argv[5],argv[6]);


    mapa.EscribirImagen("datos/imagenes/salida/salida.ppm");
}