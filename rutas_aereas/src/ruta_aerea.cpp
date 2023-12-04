#include <iostream>
#include "AlmacenRuta.h"
#include "Imagen.h"
#include <Paises.h>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {

    if(argc != 8) {
        cerr
                << "Se debe usar <Datos de paises> <mapa global> <directorio banderas> <almacén rutas> <avión> <mascara avión> <salida imagen>"
                << endl;
        exit(1);
    }
    Paises paises(argv[1], argv[3]);
    Imagen mapa(argv[2]);
    AlmacenRuta almacenRuta(argv[4]);
    Imagen avion(argv[5],argv[6]);
    string codigo_ruta;
    cout << "Elija ruta: " <<endl << almacenRuta << endl;
    //cin>>codigo_ruta;
    codigo_ruta = "R1";
    Ruta ruta = almacenRuta.getRuta(codigo_ruta);
    for(int i = 0; i<ruta.getPuntos().size();i++) {
        bool encontrado = false;
        for(Paises::Iterator it = paises.begin(); it != paises.end() && !encontrado; it++){
            if(ruta[i].getX() == (*it).getPunto().getX() && ruta[i].getY() == (*it).getPunto().getY()) {
                double punto_medio_x = (*it).Bandera().Filas()/2;
                double punto_medio_y = (*it).Bandera().Columnas()/2;
                mapa.PutImagen((*it).getPunto().getX()-punto_medio_x,(*it).getPunto().getY()-punto_medio_y, (*it).Bandera(), OPACO);
                encontrado = true;
            }
        }
        double theta_radians = atan2(ruta[i+1].getY() - ruta[i].getY(), ruta[i+1].getX() - ruta[i].getX());
        double theta_degrees = fmod((180.0 / M_PI) * theta_radians + 360.0, 360.0);

        Imagen avion_rotado = Rota(avion, theta_degrees);
        mapa.PutImagen(ruta[i].getX()-avion_rotado.Filas()/2, ruta[i].getY()-avion_rotado.Columnas()/2, avion_rotado, OPACO);
    }

    mapa.EscribirImagen(argv[7]);
    return 0;
}