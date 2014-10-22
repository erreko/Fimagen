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

              this->m = new int* [cols];

              for(int i=0;i<this->cols;i++)
              {
                  this->m[i]= new int [rows];
              }

              for(int i = 0;i<this->rows;i++)
              {
                  for(int j = 0;j<this->cols;j++)
                  {
                      file >> this->m[j][i];

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
        file <<p[0]<<p[1]<<" ";

        file << this->rows << " "<< this->cols<<endl;

        file <<mval<<" ";
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

               r= (m[i][j])/255.0;

               glColor3f(r,r,r);
               glVertex2s(i,j);

            }

   }
}

void Imagen::negativo()
{
   double r,t;

   for(int j=0;j<rows;j++)
   {
       for(int i=0;i<cols;i++)
       {
           t = 255.0 - m[i][j];
           r = t/255.0;

           glColor3f(r,r,r);
           glVertex2s(i,j);
       }
   }



}

void Imagen::thold()
{

    for(int j=0;j<rows;j++)
        {
            for(int i=0;i<cols;i++)
            {
                m[i][j] = m[i][j]>=127?255:0;

                glColor3f(m[i][j],m[i][j],m[i][j]);
                glVertex2s(i,j);

            }

        }

}


