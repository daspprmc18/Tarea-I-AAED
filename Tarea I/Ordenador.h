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

            // Recorre el arreglo desde la i-ésima + 1 posición hasta n en busca de la posición que 
            // contiene el menor de todos los números, una vez que lo encuentra lo intercambia con el
            // elemento en la i-ésima posición.

            for ( int j = i + 1; j <= ultimaPosicion; ++j ) {

                if ( arreglo[j] < arreglo[min] ) // Si el elemento en la j-ésima posición es más pequeño que el mínimo, actualice mínimo.
                    min = j;
            }

            temp = arreglo[i];
            arreglo[i] = arreglo[min];
            arreglo[min] = temp;

        }
    };

    void insercion (int * arreglo, int tamano) {

        int llave = 0;
        int i = 0;

        for ( int j = 1; j < tamano; ++j ) {

            llave = arreglo[j];
            i = j - 1; // Índice de elemento inmediatamente anterior a j.

            // Ahora: comienza a comparar el i-ésimo elemento con la llave, si es mayor inserta 
            // el i-ésimo elemento en la i-ésima + 1 posición y decrementa i. Realiza lo anterior
            // hasta que el i-ésimo elemento sea menor a la llave o que i < 0.
            while ( i >= 0 && arreglo[i] > llave ) {
                arreglo[i + 1] = arreglo[i];
                --i;
            }

            arreglo[i + 1] = llave;
        }
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