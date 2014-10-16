#ifndef MATRIX_H
#define MATRIX_H
#include<fstream>
#include<iostream>
using namespace std;

class matrix
{

        private:
        int rows;
        int cols;

        int **m;

        public:


    matrix();
    matrix(int rows, int cols);

    int getRows();
    void setRows(int value);
    int getCols();
    void setCols(int value);

    void showMatrix();
    void suma(matrix a, matrix b);
    void resta(matrix a, matrix b);
    void escalar(int a);
    void transpuesta(matrix a);
    void mul(matrix a, matrix b);
    void rell();
    void rellenar();
    void showMatrixT();

    matrix& operator +(const matrix &valor);
    matrix& operator -(const matrix &valor);
    matrix& operator *(const matrix &valor);


    friend ostream& operator <<(ostream &os, const matrix &valor);

    void rellenar2(string c);
    void imprimir(string c);




};



#endif // MATRIX_H
