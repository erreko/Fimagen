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
void reshape();
void keyboard(unsigned char key, int x, int y);
void keySpecial (int key);

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
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    gluOrtho2D(0,640,480,0);

    glutDisplayFunc(display);
 //   glutReshapeFunc(reshape);

//    glutKeyboardFunc(keyboard);
//    glutSpecialFunc(keySpecial);

    glutMainLoop();

     return EXIT_SUCCESS;



    return 0;
}


void display()
{
          glClear(GL_COLOR_BUFFER_BIT);
          glBegin(GL_POINTS);

       //   a.pintar();
         b=a;
       //  b.negativo();
        b.thold();

          glEnd();
          glFlush();
      //    glutPostRedisplay();
}

void reshape()
{
//    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,640,480,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {

/*    case GLUT_KEY_UP:
        TraslateY(0.1);
        printf("Arriba\n");
        break;
    case GLUT_KEY_DOWN:
        TraslateY(-0.1);
        printf("Abajo\n");
        break;
    case 'b':
        glPolygonMode(GL_FRONT,GL_LINE);
        glPolygonMode(GL_BACK,GL_LINE);
        printf("Modo de poligono de linea\n");
        break;
*/
    case 'n':
      b.negativo();
        break;
    }
}


void keySpecial (int key)
{
    switch(key)
    {
/*    case GLUT_KEY_UP:
        TraslateY(0.1);
        printf("Arriba\n");
        break;
    case GLUT_KEY_DOWN:
        TraslateY(-0.1);
        printf("Abajo\n");
        break;
    case GLUT_KEY_RIGHT:
        TraslateX(0.1);
        printf("Derecha\n");
        break;
    case GLUT_KEY_LEFT:
        TraslateX(-0.1);
        printf("Izquierda\n");
        break;
  */  }
}


