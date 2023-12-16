#include <iostream>
#include "AlmacenRuta.h"
#include "Imagen.h"
#include <Paises.h>
#include <cmath>
#include <vector>
/**
 * @file ruta_aerea.cpp
 * @brief Programa principal del proyecto que genera la imagen de una ruta concreta.
 * @author Javier Lama Jiménez
 * @author Iván Rodríguez Chacón
 */

using namespace std;

int main(int argc, char *argv[]) {

   if (argc != 7) {
      cerr
              << "Se debe usar <Datos de paises> <mapa global> <directorio banderas> <almacén rutas> <avión> <mascara avión>"
              << endl;
      exit(1);
   }

   Imagen mapa(argv[2]);
   Punto::setTotalFilas(mapa.Filas());
   Punto::setTotalColumnas(mapa.Columnas());
   Paises paises(argv[1], argv[3]);
   AlmacenRuta almacenRuta(argv[4]);
   Imagen avion(argv[5], argv[6]);
   string codigo_ruta;
   cout << "Elija ruta: " << endl << almacenRuta << endl;
   cin >> codigo_ruta;
   Ruta ruta = almacenRuta.getRuta(codigo_ruta);
   vector<string> paises_ruta;

   //Bucle que recorre cada punto y situa sus banderas en el mapa si pertenecen a un pais
   for (int i = 0; i < ruta.size(); i++) {
      Paises::const_Iterator it = paises.find(ruta[i]);
      if (!(i % 2) && it != paises.cend()) {
         double punto_medio_x = (*it).Bandera().Filas() / 2.0;
         double punto_medio_y = (*it).Bandera().Columnas() / 2.0;
         mapa.PutImagen((*it).getPunto().getX() - punto_medio_x, (*it).getPunto().getY() - punto_medio_y,
                        (*it).Bandera(), BLENDING);
         paises_ruta.push_back((*it).Nombre());
      }

      //Descomentar esta parte para obtener aviones de llegada a cada pais
      /*
      if(!(i%2) && i != 0 && i != ruta.getPuntos().size()-1) {

          double rot_radianes = atan2(ruta[i].getX() - ruta[i-1].getX(), ruta[i].getY() - ruta[i-1].getY());
          //Rotar aviones y pegarlos
          Imagen avion_rotado = Rota(avion, rot_radianes);
          mapa.PutImagen(ruta[i].getX()-avion_rotado.Filas()/2, ruta[i].getY()-avion_rotado.Columnas()/2, avion_rotado, OPACO);
      }*/
      //Calcular radianes para obtener rotacion
      double pos_primero = i + 1 >= ruta.getPuntos().size() ? i - 1 : i;
      double pos_segundo = i + 1 >= ruta.getPuntos().size() ? i : i + 1;
      double rot_radianes = atan2(ruta[pos_segundo]
                                          .getX() - ruta[pos_primero].getX(),
                                  ruta[pos_segundo].getY() - ruta[pos_primero].getY());
      //Rotar aviones y pegarlos
      Imagen avion_rotado = Rota(avion, rot_radianes);
      mapa.PutImagen(ruta[i].getX() - avion_rotado.Filas() / 2.0, ruta[i].getY() - avion_rotado.Columnas() / 2.0,
                     avion_rotado, OPACO);
   }
   string salida = "../datos/imagenes/salida/" + codigo_ruta + ".ppm";
   mapa.EscribirImagen(salida.c_str());
   cout << "Imagen creada exitosamente" << endl;
   cout << "Paises recorridos: " << endl;
   for (int i = 0; i < paises_ruta.size(); i++) {
      cout << paises_ruta[i] ;
      if(i != paises_ruta.size()-1)
         cout << " -> ";
   }
   return 0;
}