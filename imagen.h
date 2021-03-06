#ifndef IMAGEN_H
#define IMAGEN_H
#include "matrix.h"

class Imagen : public Matrix
{
protected:

    char p[2];
    int mval;

public:
    Imagen();
//    ~Imagen();
    void relli(string c);
    void pintar();
    void imprimiri(string c);
    void negativo();
    void thold(int a);
    void copia(const Imagen &a);
    void original();
    void oscurecer();
    void iluminar();

    Imagen operator!();

};

#endif // IMAGEN_H

