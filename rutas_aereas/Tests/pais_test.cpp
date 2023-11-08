#include <iostream>
#include <Pais.h>
#include <Punto.h>

using namespace std;

int main() {
    cout<<"Introduzca el nombre del pais, las coordenadas y el path de la bandera: "<<endl;
    Pais pais;
    cin >> pais;

    cout << pais.Nombre()<<endl<< pais.Coordenadas().getX()<< ", " << pais.Coordenadas().getY()<<endl<<pais.PathBandera() << endl;
    Punto salida = coordenadas_aPunto(pais.Coordenadas().getX(), pais.Coordenadas().getY(), 768, 1536);
    cout << salida.getX() << ", " << salida.getY() << endl;

    return 0;
}