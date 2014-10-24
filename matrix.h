#ifndef MATRIX_H
#define MATRIX_H
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;

class Matrix
{

        protected:
        int rows;
        int cols;

        int **m;

        public:


    Matrix();
    Matrix(int rows, int cols);
//    ~Matrix();

    int getRows();
    void setRows(int value);
    int getCols();
    void setCols(int value);

    void showMatrix();
    void suma(Matrix a, Matrix b);
    void resta(Matrix a, Matrix b);
    void escalar(int a);
    void transpuesta(Matrix a);
    void mul(Matrix a, Matrix b);
    void rell();
    void rellenar();
    void showMatrixT();

    Matrix& operator +(const Matrix &valor);
    Matrix& operator -(const Matrix &valor);
    Matrix& operator *(const Matrix &valor);


    friend ostream& operator <<(ostream &os, const Matrix &valor);

    void rellenar2(string c);
    void imprimir(string c);
    int coo(int i,int j);

    static Matrix &suma(const Matrix &a, const Matrix &b, const Matrix &c);



    int **getM() const;
    void setM(int **value);
};


#endif // MATRIX_H
