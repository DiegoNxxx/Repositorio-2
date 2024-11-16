#include <iostream>
using namespace std;


void increasePrice(double* price) {
    *price *= 1.2;
};


int main(){
    
    //pointer
    // un puntero es una variable que almacena la direccion de memoria de otra variable

    int number = 10;

    int* pointer = &number; 

    std::cout << "direccion de memoria de puntero" << pointer << std::endl;
    // el operador & nos permite obtener la direccion de memoria

    std::cout << "direccion variablle" << &number << std::endl;

    cout << "Este es el valor del puntero " << *pointer << endl;

    //se permite realizar nuevas asignaciones una vez dereferenciado el puntero
    *pointer = 20;

    std::cout << "nuevo valor del number" << number << std::endl;

    //EJERCICIO
    int x = 10;
    int y = 20;
    int* ptr = &x;
    *ptr *= 2;
    ptr = &y;
    *ptr *= 3;


    // punteros constantes y constantes
    //  1.- Los datos son constantes pero el puntero puede ser modificado

    const int x2 = 10;
    const int* ptr2 = &x2;

    cout << "memory address constante "<< ptr2 << endl;



    double price = 100;
    increasePrice(&price);
    cout << "price: " << price << endl;

    return 0;






    struct Pointer{
        int a;
        int b;
    };
        Pointer p1 = {.a:30, .b:50};

        Pointer* pValue= &p1;

        cout << "Valor de pValue" << (*pValue).a << endl;
        cout << "Valor de pValue" << pValue->b << endl;


};