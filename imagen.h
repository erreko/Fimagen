#ifndef IMAGEN_H
#define IMAGEN_H
#include "matrix.h"

class Imagen : public Matrix
{
protected:

    char p[1];
    int mval;

public:
    Imagen();
    void relli(string c);
    void pintar();
    void imprimiri(string c);
    void negativo();
    void thold();
};

#endif // IMAGEN_H

