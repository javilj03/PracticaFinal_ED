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
    cin>>codigo_ruta;
    Ruta ruta = almacenRuta.getRuta(codigo_ruta);
    for(int i = 0; i<ruta.getPuntos().size();i++) {
        bool encontrado = false;
        for(Paises::Iterator it = paises.begin(); it != paises.end() && !encontrado; it++){
            if((int)ruta[i].getX() == (int)(*it).getPunto().getX() && (int)ruta[i].getY() == (int)(*it).getPunto().getY()) {
                mapa.PutImagen((*it).getPunto().getX(), (*it).getPunto().getY(), (*it).Bandera(), OPACO);
                encontrado = true;
            }
        }
        double theta_radians = atan2(ruta[i+1].getY() - ruta[i].getY(), ruta[i+1].getX() - ruta[i].getX());
        double theta_degrees = fmod((180.0 / M_PI) * theta_radians + 360.0, 360.0);

        Imagen avion_rotado = Rota(avion, theta_degrees);
        mapa.PutImagen(ruta[i].getX(), ruta[i].getY(), avion_rotado, BLENDING);
    }

    mapa.EscribirImagen(argv[7]);
    return 0;
}