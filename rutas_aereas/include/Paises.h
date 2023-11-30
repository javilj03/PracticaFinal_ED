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
    explicit Paises(const char *fileName);
    class Iterator{
    private:
        map<std::string,Pais>::iterator iterador;
    public:
        Iterator();
        Iterator(const Iterator &other);
        Iterator(const map<string,Pais>::iterator &it);

        Iterator &operator++();
        Iterator &operator++(int);
        pair<string,Pais> operator*();
        bool operator!=(Iterator it2) const;
    };

    class const_Iterator{
    private:
        map<std::string,Pais>::const_iterator iterador;
    public:
        const_Iterator(const map<string,Pais>::const_iterator &it);
        const_Iterator &operator++();
        const_Iterator &operator++(int);
        pair<string,Pais> operator*();
        bool operator!=(const_Iterator it2) const;
    };

    const_Iterator begin() const;
    const_Iterator end() const;
    bool empty() const;
    bool insert(const pair<string,Pais>& elemento);
    bool insert(Pais pais);
    void insert(const Paises::Iterator& begin, const Paises::Iterator& end);
};

ostream &operator<<(ostream &os, const Paises &paises);
istream &operator>>(istream &is, Paises &paises);

#endif //PRACTICAFINAL_PAISES_H
