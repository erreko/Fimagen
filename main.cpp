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

void display(void);
void keyboard(unsigned char key, int x, int y);


Imagen a,b;



int main(int argc, char** argv)
{
    a.relli("window.pgm");
    b.copia(a);
    a.imprimiri("intento.pgm");

    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(150,150);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("LOL");
    gluOrtho2D(0,640,480,0);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

     return EXIT_SUCCESS;



    return 0;
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POINTS);


          b.pintar();

    glEnd();
    glFlush();
    glutPostRedisplay();


}


void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {

    case 'o':
        b.copia(a);
        break;

    case 't':
        b.copia(a);
        b.thold(90);

        break;

    case 'n':
        b.copia(a);
        b.negativo();
        break;

    case 'u':
        b.oscurecer();
        break;

    case 'i':
        b.iluminar();
        break;

    case 'g':
        b.imprimiri("Isalvada.pgm");
        break;
    }
}




