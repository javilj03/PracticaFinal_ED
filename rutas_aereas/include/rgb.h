//
// Created by ivanf on 04/11/2023.
//

#ifndef PRACTICAFINAL_RGB_H
#define PRACTICAFINAL_RGB_H


class rgb {
private:
    unsigned char red;
    unsigned char green;
    unsigned char blue;
public:
    rgb(unsigned char red = 0, unsigned char green = 0, unsigned char blue = 0);

    void set(const unsigned char &red, const unsigned char &green, const unsigned char &blue);

    unsigned char &Red();

    const unsigned char &Red() const;

    unsigned char &Green();

    const unsigned char &Green() const;

    unsigned char &Blue();

    const unsigned char &Blue() const;
};


#endif //PRACTICAFINAL_RGB_H
