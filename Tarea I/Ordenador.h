#ifndef _CLASE_ORDENADOR
#define _CLASE_ORDENADOR

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "time.h"

using namespace std;

class Ordenador {
private:


public:

    Ordenador () {
    };

    ~Ordenador () {
    };

    void seleccion (int * arreglo, int tamano) {

        int min = 0;
        int temp = 0;
        int penultimaPosicion = tamano - 2;
        int ultimaPosicion = tamano - 1;

        for ( int i = 0; i <= penultimaPosicion; ++i ) {

            min = i;

            for ( int j = i + 1; j <= ultimaPosicion; ++j ) {

                if ( arreglo[j] < arreglo[min] ) // Si el elemento en la j-ésima posición es más pequeño que el mínimo, actualice el mínimo.
                    min = j;
            }

            temp = arreglo[i];
            arreglo[i] = arreglo[min];
            arreglo[min] = temp;

        }
    };

    void insercion (int * arreglo, int tamano) {
    };

    void mergesort (int * arreglo, int tamano) {
    }

    void heapsort (int * arreglo, int tamano) {
    };

    void quicksort (int * arreglo, int tamano) {
    };

    void radixsort (int * arreglo, int tamano) {
    };

    int mediana (int * arreglo, int tamano) {
    };
};
#endif