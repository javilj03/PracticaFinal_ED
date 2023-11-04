//
// Created by ivanf on 04/11/2023.
//

#include "rgb.h"

rgb::rgb(unsigned char red, unsigned char green, unsigned char blue) {
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