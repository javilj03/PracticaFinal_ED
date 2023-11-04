//
// Created by ivanf on 04/11/2023.
//
#include <imagen.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Error: Numero de parametros incorrecto.\n";
        cerr << "Uso: " << argv[0] << " <FichImagenOriginal> <FichImagenDestino>\n";
        exit(1);
    }
    imagen im(argv[1]);
    im.EscribirImagen(argv[2]);

    return 0;
}