//
// Created by ivanf on 04/11/2023.
//
#include <Imagen.h>
#include <iostream>
#include <chrono>

using namespace std;

int main(int argc, char *argv[]) {
    auto start_time = std::chrono::high_resolution_clock::now();
    if (argc != 3) {
        cerr << "Error: Numero de parametros incorrecto.\n";
        cerr << "Uso: " << argv[0] << " <FichImagenOriginal> <FichImagenDestino>\n";
        exit(1);
    }
    Imagen im(argv[1]);
    im.EscribirImagen(argv[2]);

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    cout << "Tiempo de ejecucion: " << duration.count() << "ms" << endl;
    return 0;
}