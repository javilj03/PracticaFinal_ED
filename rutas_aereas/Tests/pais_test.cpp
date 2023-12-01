#include <iostream>
#include <Pais.h>
#include <Punto.h>

using namespace std;

int main() {
    cout<<"Introduzca el nombre del pais, las punto y el path de la bandera: "<<endl;
    Pais pais;
    cin >> pais;

    cout << pais.Nombre() << endl << pais.Punto().getX() << ", " << pais.Punto().getY() << endl << pais.PathBandera() << endl;
    Punto salida = coordenadas_aPunto(pais.Punto().getX(), pais.Punto().getY(), 768, 1536);
    cout << salida.getX() << ", " << salida.getY() << endl;

    return 0;
}