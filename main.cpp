#include "imagen.h"
#include<iostream>
#include<fstream>

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


using namespace std;

void display();

Imagen a,b;

int main(int argc, char** argv)
{
    a.relli("window.pgm");
    a.imprimiri("intento.pgm");

    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(150,150);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("LOL");
    glMatrixMode(GL_PROJECTION);
    glClearColor(0.0,0.0,0.0,0.0);
    gluOrtho2D(0,640,480,0);
    glutDisplayFunc(display);
    glutMainLoop();

     return EXIT_SUCCESS;



    return 0;
}


void display()
{
          glClear(GL_COLOR_BUFFER_BIT);
          glBegin(GL_POINTS);

          a.pintar();


          glEnd();
          glFlush();
}

