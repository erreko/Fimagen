#include "matrix.h"
#include<iostream>
#include<fstream>


using namespace std;

int matrix::getRows()
{
    return this->rows;
}

void matrix::setRows(int value)
{
   this->rows = value;
}

int matrix::getCols()
{
    return this->cols;
}

void matrix::setCols(int value)
{
   this->cols = value;
}
matrix::matrix()
{
  m = NULL;
  rows =0;
  cols =0;
}

matrix::matrix(int rows, int cols)
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
                 m[i][j] = 0;

            }
       }
}

void matrix::showMatrix()
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

void matrix::suma(matrix a, matrix b)
{

    for(int i =0;i<rows; i++)
    {
        for(int j=0;j<cols;j++)
        {
            m[i][j] = a.m[i][j] + b.m[i][j];
        }
    }
}

void matrix::resta(matrix a, matrix b)
{
    for(int i =0;i<rows; i++)
    {
        for(int j=0;j<cols;j++)
        {
            m[i][j] = a.m[i][j] - b.m[i][j];
        }
    }
}

void matrix::escalar(int a)
{
    for(int i =0;i<rows; i++)
    {
        for(int j=0;j<cols;j++)
        {
            m[i][j] *= a;
        }
    }
}

void matrix::transpuesta(matrix a)
{
    for(int i =0;i<cols; i++)
    {
        for(int j=0;j<rows;j++)
        {
            m[j][i]= a.m[i][j];
        }
    }

}

void matrix::mul(matrix a, matrix b)
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

void matrix::rellenar()
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

void matrix::showMatrixT()
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


matrix &matrix::operator +(const matrix &valor)
 {
    matrix *c = new matrix(valor.rows, valor.cols);

        for(int i = 0; i<c->rows; i++)
        {
            for(int j = 0; j<c->cols; j++)
            {
                c->m[i][j] = this->m[i][j] + valor.m[i][j];
            }
        }

        return *c;
 }

matrix &matrix::operator -(const matrix &valor)
 {
    matrix *c = new matrix(valor.rows, valor.cols);

        for(int i = 0; i<c->rows; i++)
        {
            for(int j = 0; j<c->cols; j++)
            {
                c->m[i][j] = this->m[i][j] - valor.m[i][j];
            }
        }

        return *c;
 }

matrix &matrix:: operator *(const matrix &valor)
{
    matrix *c = new matrix(valor.rows, valor.cols);

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


ostream& operator <<(ostream &os, const matrix &valor)
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

void matrix::rellenar2(string c)
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


void matrix::imprimir(string c)
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
