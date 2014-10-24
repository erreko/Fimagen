#include "matrix.h"
#include<iostream>
#include<fstream>

using namespace std;

int Matrix::getRows()
{
    return this->rows;
}

void Matrix::setRows(int value)
{
   this->rows = value;
}

int Matrix::getCols()
{
    return this->cols;
}

void Matrix::setCols(int value)
{
   this->cols = value;
}

int **Matrix::getM() const
{
    return m;
}

void Matrix::setM(int **value)
{
    m = value;
}
Matrix::Matrix()
{
    m = NULL;
    rows =0;
    cols =0;
}

Matrix::Matrix(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;

    m = new int*[rows];
    for (int i =0; i< rows; i++)
    {
        m[i] = new int[cols];

    }

    for (int i =0; i<rows; i++)
       {
        for (int j=0; j <cols ; j++)
            {
                 m[i][j] = 2;

            }
       }
}
/*
Matrix::~Matrix()
{
    for(int i = 0; i<rows; i++)
    {
        delete[] m[i];
    }
    delete[] m;
}
*/

void Matrix::showMatrix()
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout << m[i][j] << " " ;
        }
        cout << endl;
    }

}

void Matrix::suma(Matrix a, Matrix b)
{

    for(int i =0;i<rows; i++)
    {
        for(int j=0;j<cols;j++)
        {
            m[i][j] = a.m[i][j] + b.m[i][j];
        }
    }
}

void Matrix::resta(Matrix a, Matrix b)
{
    for(int i =0;i<rows; i++)
    {
        for(int j=0;j<cols;j++)
        {
            m[i][j] = a.m[i][j] - b.m[i][j];
        }
    }
}

void Matrix::escalar(int a)
{
    for(int i =0;i<rows; i++)
    {
        for(int j=0;j<cols;j++)
        {
            m[i][j] *= a;
        }
    }
}

void Matrix::transpuesta(Matrix a)
{
    for(int i =0;i<cols; i++)
    {
        for(int j=0;j<rows;j++)
        {
            m[j][i]= a.m[i][j];
        }
    }

}

void Matrix::mul(Matrix a, Matrix b)
{
    int **d;
    d = new int*[rows];
    for(int i=0;i<rows;i++)
    {
        d[i]= new int[cols];
    }

    for(int i =0;i<rows; i++)
    {
        for(int j=0;j<cols;j++)
        {
            for(int k=0;k<cols;k++)
            {
               m[i][j]= m[i][j] + a.m[i][k]*b.m[k][j];
            }
        }
    }
}

void Matrix::rellenar()
{
    int z =1;
    for(int i =0;i<rows; i++)
    {
        for(int j=0;j<cols;j++)
        {
           // cin >> m[i][j];
            m[i][j] = z ;
            z++;
        }
    }

}

void Matrix::showMatrixT()
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout << m[i][j] << " " ;
        }
        cout << endl;
    }

}

/*matrix &matrix::suma(const matrix &a, const matrix &b)
{
    return a+b;
}
*/
Matrix &Matrix::operator +(const Matrix &valor)
 {
    Matrix *c = new Matrix(valor.rows, valor.cols);

        for(int i = 0; i<c->rows; i++)
        {
            for(int j = 0; j<c->cols; j++)
            {
                c->m[i][j] = this->m[i][j] + valor.m[i][j];
            }
        }

        return *c;
 }

Matrix &Matrix::operator -(const Matrix &valor)
 {
    Matrix *c = new Matrix(valor.rows, valor.cols);

        for(int i = 0; i<c->rows; i++)
        {
            for(int j = 0; j<c->cols; j++)
            {
                c->m[i][j] = this->m[i][j] - valor.m[i][j];
            }
        }

        return *c;
 }

Matrix &Matrix:: operator *(const Matrix &valor)
{
    Matrix *c = new Matrix(valor.rows, valor.cols);

        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                c->m[i][j]=0;
                for (int k = 0; k < this->cols; k++)
                {
                    c->m[i][j]=c->m[i][j] + (this->m[i][k]*valor.m[k][j]);
                }
            }
        }
        return *c;
}


ostream& operator <<(ostream &os, const Matrix &valor)
{
    for(int i = 0; i<valor.rows; i++)
    {
        for(int j = 0; j<valor.cols; j++)
        {
            os<<valor.m[i][j]<<" ";
        }
        os<<"\n";
    }
    return os;
}

int Matrix::coo(int i, int j)
{
 return this->m[i][j];
}

void Matrix::rellenar2(string c)
{
    int i = 0;
    int j = 0;
    ifstream file;
    file.open(c.c_str());
    if(file.is_open())
    {
        file >> this->rows;
        file >> this->cols;

              this->m = new int* [rows];

              for(i=0;i<this->rows;i++)
              {
                  this->m[i]= new int [cols];
              }

              for(i = 0;i<this->rows;i++)
              {
                  for(j = 0;j<this->cols;j++)
                  {
                      file >> this->m[i][j];

                  }
              }

     file.close();

    }

}


void Matrix::imprimir(string c)
{
    int i = 0;
    int j = 0;
    ofstream file;
    file.open(c.c_str());
    if(file.is_open())
    {
        file << this->rows << " "<< this->cols<<endl;


              for(i = 0;i<this->rows;i++)
              {
                  for(j = 0;j<this->cols;j++)
                  {
                      file << this->m[i][j] << " ";

                  }

                  file << endl;
              }

      file.close();
    }

}
