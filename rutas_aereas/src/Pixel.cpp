#include "Pixel.h"

Pixel::Pixel(const unsigned char &red, const unsigned char &green, const unsigned char &blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}

void Pixel::set(const unsigned char &red, const unsigned char &green, const unsigned char &blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}

unsigned char &Pixel::Red() {
    return red;
}

const unsigned char &Pixel::Red() const {
    return red;
}

unsigned char &Pixel::Green() {
    return green;
}

const unsigned char &Pixel::Green() const {
    return green;
}

unsigned char &Pixel::Blue() {
    return blue;
}

const unsigned char &Pixel::Blue() const {
    return blue;
}

bool Pixel::operator==(const int &n) const {
    return (this->red == n && this->green == n && this->blue == n);
}

bool Pixel::operator!=(const int &n) const {
    return (this->red != n || this->green != n || this->blue != n);
}

Pixel Pixel::media(const Pixel &rgb2) const {
    int red = (int) this->red + (int) rgb2.red;
    int green = (int) this->green + (int) rgb2.green;
    int blue = (int) this->blue + (int) rgb2.blue;
    Pixel salida(red / 2, green / 2, blue / 2);
    return salida;
}