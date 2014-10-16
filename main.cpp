#include "matrix.h"
#include<iostream>
#include<fstream>



using namespace std;

int main()
{
    matrix a;



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

    a.rellenar2("123.txt");

    cout<<a<<endl;


    a.imprimir("txt2.txt");


    return 0;
}
