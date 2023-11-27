#include <iostream>
#include <fstream>
#include "AlmacenRuta.h"
#include "Ruta.h"

int main() {
   // Crear un objeto AlmacenRutas
   AlmacenRuta almacenRutas;

   // Abrir el archivo de entrada
   ifstream archivoEntrada("/home/lamadindon/Documentos/ObsidianVaultEstudios/Universidad/2/PrimerCuatri/ED/Practicas/PracticaFinal_ED/datos/almacen_rutas.txt");  // Asegúrate de cambiar "ruta.txt" al nombre real de tu archivo

   // Verificar si el archivo se abrió correctamente
   if (!archivoEntrada) {
      cerr << "No se pudo abrir el archivo de entrada." << endl;
      return 1;  // Salir con código de error
   }

   archivoEntrada >> almacenRutas;

   archivoEntrada.close();
   cout << "Contenido de AlmacenRutas:\n" << almacenRutas << endl;

   return 0;
}
