#include "matrix.h"
#include<iostream>
#include<fstream>



using namespace std;

int main()
{
    imagen a;



 /*   a.rellenar();
    a.showMatrix();
    cout << endl;

    b.rellenar();
    b.showMatrix();
    cout << endl;

    c = a + b;

    c.showMatrix();

    cout << endl;

    c = a - b;

    c.showMatrix();

    cout << endl;

    c = a * b;
*/

    a.relli("pet.pgm");

    a.imprimir("imprimiendoPET.txt");

  //  a.showMatrix();

    return 0;
}
