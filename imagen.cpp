#include "imagen.h"
#include "matrix.h"

#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#  include <math.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#endif

Imagen::Imagen()
{
}

/*
Imagen::~Imagen()
{
for(int i = 0; i<rows; i++)
  {
      delete[] m[i];
  }
  delete[] m;
}
*/
void Imagen::relli(string c)
{

    ifstream file;
    file.open(c.c_str());
    if(file.is_open())
    {
        file >> this->p;
      //  file >> this->nmagic;
        file >> this->cols;
        file >> this->rows;
        file >> this->mval;

              this->m = new int* [rows];

              for(int i=0;i<this->rows;i++)
              {
                  this->m[i]= new int [cols];
              }

              for(int i = 0;i<this->rows;i++)
              {
                  for(int j = 0;j<this->cols;j++)
                  {
                      file >> this->m[i][j];

                  }
              }

     file.close();

    }


}

void Imagen::imprimiri(string c)
{
    int i = 0;
    int j = 0;
    ofstream file;
    file.open(c.c_str());
    if(file.is_open())
    {
        file <<p[0]<<p[1]<<p[2]<<endl;

        file << this->cols << " "<< this->rows<<endl;

        file <<mval<<endl;
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


void Imagen::pintar()
{


   int i,j;
   double r;
   for(j=0;j<rows;j++)
   {
       for(i=0;i<cols;i++)
           {

               r= (m[j][i])/255.0;

               glColor3f(r,r,r);
               glVertex2s(i,j);

            }

   }

}

void Imagen::negativo()
{
   double t;


   for(int j=0;j<rows;j++)
   {
       for(int i=0;i<cols;i++)
       {
           t = 255.0 - m[j][i];
           m[j][i] = t;
       }
   }



}

void Imagen::thold(int a)
{

    for(int j=0;j<rows;j++)
        {
            for(int i=0;i<cols;i++)
            {
                m[j][i] = m[j][i]>=a?255:0;

            }

        }

}

void Imagen::copia(const Imagen &a)
{
    this->rows = a.rows;
    this->cols = a.cols;
    this->p[0] = a.p[0];
    this->p[1] = a.p[1];
    this->p[2] = a.p[2];
    this->mval = a.mval;

    this->m = new int* [rows];

    for(int i=0;i<this->rows;i++)
    {
        this->m[i]= new int [cols];
    }

    for(int i = 0;i<this->rows;i++)
    {
        for(int j = 0;j<this->cols;j++)
        {
           this->m[i][j] = a.m[i][j];
        }
    }


}

void Imagen::original()
{
    int i,j;
   double r;
   for(j=0;j<rows;j++)
   {
       for(i=0;i<cols;i++)
           {
               r= (m[j][i]);
           }
   }
}

void Imagen::oscurecer()
{
    for(int j=0;j<rows;j++)
        {
            for(int i=0;i<cols;i++)
            {
                m[j][i] = m[j][i]-1;

            }

        }

}

void Imagen::iluminar()
{
    for(int j=0;j<rows;j++)
        {
            for(int i=0;i<cols;i++)
            {
                m[j][i] = m[j][i]+1;

            }

        }

}

/*Imagen Imagen::operator!()
{

    int i = 0;
    int j = 0;

    Imagen z;

    z.rows = this->rows;
    z.cols = this->cols;

    z.m = new int* [z.rows];

    for(i=0;i<z.rows;i++)
    {
        z.m[i] = new int [z.cols];
    }

    for(i=0;i<z.rows;i++)
    {
        for(j=0;j<z.cols;j++)
        {
          z.m[j][i] = 255-this->m[j][i];

        }
    }

    return z;
}

*/
