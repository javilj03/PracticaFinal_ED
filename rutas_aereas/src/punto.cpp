//
// Created by lamadindon on 4/11/23.
//

#include "Punto.h"

Punto::Punto(double x, double y){
   this->x = x;
   this->y = y;
}
double Punto::getX() const {
   return x;
}
double Punto::getY() const {
   return y;
}