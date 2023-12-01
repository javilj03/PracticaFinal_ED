#ifndef PRACTICAFINAL_PAISES_H
#define PRACTICAFINAL_PAISES_H

#include <set>
#include <iostream>
#include <Pais.h>
#include <iomanip>

class Paises {
private:
   set<Pais, std::less<>> datos;

    void insertar(const char *fileName);
public:
    explicit Paises(const char *fileName);
    class Iterator{
    private:
        set<Pais>::iterator iterador;
    public:
        Iterator();
        Iterator(const Iterator &other);
        Iterator(const set<Pais>::iterator &it);

        Iterator &operator++();
        Iterator &operator++(int);
        Pais operator*() const;
        bool operator!=(Iterator it2) const;
    };

    class const_Iterator{
    private:
        set<Pais>::const_iterator iterador;
    public:
        const_Iterator(const set<Pais>::const_iterator &it);
        const_Iterator &operator++();
        const_Iterator &operator++(int);
        Pais operator*() const;
        bool operator!=(const_Iterator it2) const;
    };

    const_Iterator begin() const;
    const_Iterator end() const;
    bool empty() const;
    bool insert(Pais pais);
    void insert(const Paises::Iterator& begin, const Paises::Iterator& end);

    void erase(const Pais& pais);
    void erase(const Paises::Iterator& it);

    void clear();
    void save(const char *fileName) const;
};

ostream &operator<<(ostream &os, const Paises &paises);
istream &operator>>(istream &is, Paises &paises);

#endif //PRACTICAFINAL_PAISES_H
