#ifndef PRACTICAFINAL_PAISES_H
#define PRACTICAFINAL_PAISES_H

#include <map>
#include <iostream>
#include <Pais.h>

class Paises {
private:
    map<std::string, Pais> datos;

    void insertar(const char *fileName);
public:
    Paises(const char *fileName);
    class Iterator{
    private:
        map<std::string,Pais>::iterator iterador;
    public:
        Iterator();
        Iterator(const Iterator &other);
        Iterator(const map<string,Pais>::iterator &it);
        Iterator operator++();
        pair<string,Pais> operator*();
    };
    Paises::Iterator begin() const;
    Paises::Iterator end() const;
    bool empty() const;
    bool insert(pair<string,Pais>);
    bool insert(Pais);
    bool insert(Paises::Iterator begin, Paises::Iterator end);
};

ostream &operator<<(ostream &os, const Paises &paises);
istream &operator>>(istream &is, Paises &paises);

#endif //PRACTICAFINAL_PAISES_H
