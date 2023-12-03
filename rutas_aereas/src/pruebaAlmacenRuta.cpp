#include <iostream>
#include <fstream>
#include "AlmacenRuta.h"
#include "Ruta.h"

int main() {
   // Crear un objeto AlmacenRutas
   AlmacenRuta almacenRutas;

   // Abrir el archivo de entrada
   ifstream archivoEntrada("/home/lamadindon/Documentos/ObsidianVaultEstudios/Universidad/2/PrimerCuatri/ED/Practicas/PracticaFinal_ED/datos/almacen_rutas.txt");

   if (!archivoEntrada) {
      cerr << "No se pudo abrir el archivo de entrada." << endl;
      return 1;
   }

   archivoEntrada >> almacenRutas;

   archivoEntrada.close();
   cout << "Contenido de AlmacenRutas:\n" << almacenRutas << endl;

   return 0;
}
