//
// Created by ivanf on 04/11/2023.
//

#include "rgb.h"

rgb::rgb(const unsigned char &red, const unsigned char &green, const unsigned char &blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}

void rgb::set(const unsigned char &red, const unsigned char &green, const unsigned char &blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}

unsigned char &rgb::Red() {
    return red;
}

const unsigned char &rgb::Red() const {
    return red;
}

unsigned char &rgb::Green() {
    return green;
}

const unsigned char &rgb::Green() const {
    return green;
}

unsigned char &rgb::Blue() {
    return blue;
}

const unsigned char &rgb::Blue() const {
    return blue;
}

rgb rgb::operator+(const rgb &rgb2) const {
    rgb salida(this->red + rgb2.red, this->green + rgb2.green, this->blue + rgb2.blue);
    return salida;
}

rgb rgb::operator/(const int &n) const {
    rgb salida(this->red / n, this->green / n, this->blue / n);
    return salida;
}

bool rgb::operator==(const int &n) const {
    return (this->red == n && this->green == n && this->blue == n);
}

bool rgb::operator!=(const int &n) const {
    return (this->red != n || this->green != n || this->blue != n);
}

rgb rgb::media(const rgb &rgb2) const {
    int red = (int) this->red + (int) rgb2.red;
    int green = (int) this->green + (int) rgb2.green;
    int blue = (int) this->blue + (int) rgb2.blue;
    rgb salida(red / 2, green / 2, blue / 2);
    return salida;
}