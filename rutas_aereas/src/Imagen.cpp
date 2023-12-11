#include "Imagen.h"

/**
 * @file Imagen.cpp
 * @brief Implementación de la clase Imagen.
 * @author Iván Rodríguez Chacón
 */

using namespace std;

void Imagen::asignarMemoria(const int &filas, const int &columnas, Pixel *buffer) {
    this->filas = filas;
    this->columnas = columnas;
    if (filas != 0 && columnas != 0) {
        liberar();

        this->datos = new Pixel *[filas];


        if (buffer != nullptr)
            this->datos[0] = buffer;
        else
            this->datos[0] = new Pixel[filas * columnas];

        for (int i = 1; i < filas; i++)
            this->datos[i] = this->datos[i - 1] + columnas;
    } else
        this->datos = nullptr;
}

void Imagen::copiar(const Imagen &im) {
    asignarMemoria(im.filas, im.columnas);
    for (int i = 0; i < filas * columnas; i++)
        this->datos[0][i] = im.datos[0][i];
}

void Imagen::liberar() {
    if (this->datos != nullptr) {
        delete[] this->datos[0];
        delete[] this->datos;
    }
    if (this->mascara != nullptr) {
        delete[] this->mascara[0];
        delete[] this->mascara;
    }
}

Imagen::Imagen(const int &filas, const int &columnas, const int &filas_mascara, const int &columnas_mascara) {
    asignarMemoria(filas, columnas);
    if(filas_mascara!=0 && columnas_mascara!=0){
        this->mascara = new unsigned char *[filas_mascara];
        this->mascara[0] = new unsigned char[filas_mascara * columnas_mascara]{0};
        for (int i = 1; i < filas_mascara; i++)
                    this->mascara[i] = this->mascara[i - 1] + columnas_mascara;
    }
}

Imagen::Imagen(const Imagen &im) {
    copiar(im);
}

Imagen::Imagen(const char *nombre, const char *nombre_mascara) {
    LeerImagen(nombre, nombre_mascara);
}

void Imagen::LeerImagen(const char *nombre, const char *nombre_mascara) {
    if (LeerTipoImagen(nombre, this->filas, this->columnas) != TipoImagen::IMG_PPM) {
        cerr << "Error: La Imagen no es de tipo PPM" << endl;
        exit(2);
    }

    unsigned char *buffer = new unsigned char[this->filas * this->columnas * sizeof(Pixel)];
    LeerImagenPPM(nombre, this->filas, this->columnas, buffer);

    this->asignarMemoria(this->filas, this->columnas, (Pixel *) buffer);

    if (nombre_mascara != nullptr)
        this->LeerMascara(nombre_mascara);
}

void Imagen::LeerMascara(const char *nombre) {
    int filas_mascara;
    int columnas_mascara;
    if (LeerTipoImagen(nombre, filas_mascara, columnas_mascara) != TipoImagen::IMG_PGM) {
        cerr << "Error: La máscara no es de tipo PGM" << endl;
        exit(2);
    }
    if (filas_mascara != this->filas || columnas_mascara != this->columnas) {
        cerr << "Error: La máscara no tiene el mismo tamaño que la Imagen" << endl;
        exit(3);
    }

    unsigned char *aux = new unsigned char[filas_mascara * columnas_mascara];
    LeerImagenPGM(nombre, filas_mascara, columnas_mascara, aux);

    if (this->mascara != nullptr) {
        delete[] this->mascara[0];
        delete[] this->mascara;
    }
    this->mascara = new unsigned char *[filas_mascara];
    this->mascara[0] = aux;
    for (int i = 1; i < filas_mascara; i++)
        this->mascara[i] = this->mascara[i - 1] + columnas_mascara;
}

void Imagen::EscribirImagen(const char *nombre) const {
    EscribirImagenPPM(nombre, (unsigned char *) this->datos[0], this->filas, this->columnas);
}

Imagen::~Imagen() {
    liberar();
}

const int &Imagen::Filas() const { return this->filas; }

const int &Imagen::Columnas() const { return this->columnas; }

Imagen &Imagen::operator=(const Imagen &im) {
    if (this != &im) {
        liberar();
        copiar(im);
    }
    return *this;
}

void Imagen::PutImagen(const int &i, const int &j, const Imagen &im, const Tipo_Pegado &tipo) {


    int parada_filas = im.filas < (this->filas - i) ? im.filas : (this->filas - i);
    int parada_columnas = im.columnas < (this->columnas - j) ? im.columnas : (this->columnas - j);

    if (tipo == OPACO) {
        for (int fila = 0; fila < parada_filas; fila++)
            for (int columna = 0; columna < parada_columnas; columna++)
                if(im.mascara== nullptr || im.mascara[fila][columna] == 255)
                    this->datos[i + fila][j + columna] = im.datos[fila][columna];

    } else if (tipo == BLENDING) {
        for (int fila = 0; fila < parada_filas; fila++)
            for (int columna = 0; columna < parada_columnas; columna++)
                if (im.mascara == nullptr|| im.mascara[fila][columna] == 255)
                    this->datos[i + fila][j + columna] = this->datos[i + fila][j + columna].media(im.datos[fila][columna]);
    }
}

Pixel &Imagen::operator()(const int &i, const int &j) {
    if (i < 0 || i >= this->filas || j < 0 || j >= this->columnas)
        throw std::out_of_range("Error: Índices fuera de rango");

    return this->datos[i][j];
}

const Pixel &Imagen::operator()(const int &i, const int &j) const {
    if (i < 0 || i >= this->filas || j < 0 || j >= this->columnas)
        throw std::out_of_range("Error: Índices fuera de rango");

    return this->datos[i][j];
}

unsigned char **Imagen::Mascara() const {
    return this->mascara;
}

unsigned char **Imagen::Mascara() {
    return this->mascara;
}

Imagen Rota(const Imagen &Io, const double &angulo) {
    double rads = angulo;
    double coseno = cos(angulo);
    double seno = sin(angulo);
    //Para obtener las dimensiones de la Imagen
    int rcorners[4], ccorners[4];
    int newimgrows, newimgcols;
    double new_row_min, new_col_min, new_row_max, new_col_max;
    double inter, inter1;
    rcorners[0] = 0;
    rcorners[1] = 0;
    ccorners[0] = 0;
    ccorners[2] = 0;
    rcorners[2] = Io.Filas() - 1;
    rcorners[3] = Io.Filas() - 1;
    ccorners[1] = Io.Filas() - 1;
    ccorners[3] = Io.Filas() - 1;
    new_row_min = 0;
    new_col_min = 0;
    new_row_max = 0;
    new_col_max = 0;
    newimgrows = 0;
    newimgcols = 0;
    for (int count = 0; count < 4; count++) {
        inter = rcorners[count] * coseno + ccorners[count] * seno;

        if (inter < new_row_min)
            new_row_min = inter;
        if (inter > new_row_max)
            new_row_max = inter;
        inter1 = -rcorners[count] * seno + ccorners[count] * coseno;

        if (inter1 < new_col_min)
            new_col_min = inter1;
        if (inter1 > new_col_max)
            new_col_max = inter1;
    }

    newimgrows = (unsigned) ceil((double) new_row_max - new_row_min);
    newimgcols = (unsigned) ceil((double) new_col_max - new_col_min);

    Imagen Iout(newimgrows, newimgcols,newimgrows,newimgcols);
    for (int rows = 0; rows < newimgrows; rows++) {
        for (int cols = 0; cols < newimgcols; cols++) {
            float oldrowcos = ((float) rows + new_row_min) * cos(-rads);
            float oldrowsin = ((float) rows + new_row_min) * sin(-rads);
            float oldcolcos = ((float) cols + new_col_min) * cos(-rads);
            float oldcolsin = ((float) cols + new_col_min) * sin(-rads);
            float old_row = oldrowcos + oldcolsin;
            float old_col = -oldrowsin + oldcolcos;
            old_row = ceil((double) old_row);
            old_col = ceil((double) old_col);
            if ((old_row >= 0) && (old_row < Io.Filas()) &&
                (old_col >= 0) && (old_col < Io.Columnas())) {
                Iout(rows, cols) = Io(old_row, old_col);
                if (Io.Mascara() != nullptr)
                    Iout.Mascara()[rows][cols] = Io.Mascara()[(int)old_row][(int)old_col];

            } else
                Iout(rows, cols).Red() = Iout(rows, cols).Green() = Iout(rows, cols).Blue() = 255;
        }
    }
    return Iout;

}
