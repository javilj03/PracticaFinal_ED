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
    rgb(const unsigned char &red = 0, const unsigned char &green = 0, const unsigned char &blue = 0);

    void set(const unsigned char &red, const unsigned char &green, const unsigned char &blue);

    unsigned char &Red();

    const unsigned char &Red() const;

    unsigned char &Green();

    const unsigned char &Green() const;

    unsigned char &Blue();

    const unsigned char &Blue() const;

    rgb operator+(const rgb &rgb2) const;

    rgb operator/(const int &n) const;

    bool operator==(const int &n) const;

    bool operator!=(const int &n) const;

    rgb media(const rgb &rgb2) const;
};


#endif //PRACTICAFINAL_RGB_H
