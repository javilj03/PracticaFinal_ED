#include <Paises.h>
#include <iostream>


using namespace std;

int main(int argc, char *argv[]) {
    if(argc!=3){
        cerr<<"Error: El programa debe recibir dos argumentos"<<endl;
        exit(-1);
    }
    //std::cout << std::fixed << std::setprecision(15);
    Paises conjunto(argv[1]);
    cout<<conjunto<<endl;
    conjunto.save(argv[2]);
    return 0;
}