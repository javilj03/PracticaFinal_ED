//
// Created by ivanf on 04/11/2023.
//

#ifndef PRACTICAFINAL_RGB_H
#define PRACTICAFINAL_RGB_H


class rgb {
private:
    unsigned char red = 0;
    unsigned char green = 0;
    unsigned char blue = 0;
public:
    rgb(unsigned char red = 0, unsigned char green = 0, unsigned char blue = 0);

    unsigned char &Red();

    const unsigned char &Red() const;

    unsigned char &Green();

    const unsigned char &Green() const;

    unsigned char &Blue();

    const unsigned char &Blue() const;
};


#endif //PRACTICAFINAL_RGB_H
