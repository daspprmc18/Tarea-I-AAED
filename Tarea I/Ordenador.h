#ifndef _CLASE_ORDENADOR
#define _CLASE_ORDENADOR

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "time.h"

using namespace std;

class Ordenador {
private:

    void merge (int * arreglo, int posInicial, int posMedia, int posFinal) {

        int tamSubIzq = posMedia - posInicial + 1; // La distancia entre el inicio y el punto medio, se le suma 1 porque el arreglo inicia en 0.
        int tamSubDer = posFinal - posMedia; // La distancia entre el final y el punto medio.

        int subIzq[tamSubIzq];
        int subDer[tamSubDer];

        // Copia los elementos desde A[posInicial..posMedia] en el subarreglo izquierdo.
        for ( int i = 0; i < tamSubIzq; ++i )
            subIzq[i] = arreglo[posInicial + i];

        // Copia los elementos desde A[posMedia+1..posFinal] en el subarreglo derecho.
        for ( int i = 0; i < tamSubDer; ++i )
            subDer[i] = arreglo[posMedia + 1 + i]; // Dado que el arreglo está numerado de 0...n-1 hay que sumar 1 a la posicion media del arreglo completo
        // para llegar al primer elemento del subarreglo derecho.

        int i = 0; // Índice para moverse por el subarreglo izquierdo
        int j = 0; // Índice para moverse por el subarreglo derecho.
        int m = posInicial; // Índice para moverse por el arreglo a ordenar.

        // Mientras no se alcance el final del subarreglo izquierdo y derecho.

        while ( i < tamSubIzq && j < tamSubDer ) {

            if ( subIzq[i] <= subDer[j] )
                arreglo[m++] = subIzq[i++];
            else
                arreglo[m++] = subDer[j++];
        }

        // Aún puede haber elementos en alguno de los dos subarreglos, por ello hacemos la verificacion respectiva y copiamos los restantes.

        while ( i < tamSubIzq ) // Si la condición se cumple aún quedan elementos en el subarreglo izquierdo.
            arreglo[m++] = subIzq[i++];

        if ( j < tamSubDer )// Si la condición se cumple aún quedan elementos en el subarreglo derecho.
            arreglo[m++] = subDer[j++];
    }

    void mergesort (int * arreglo, int posInicial, int posFinal) {

        int posMedia = 0;
        if ( posInicial < posFinal ) {

            posMedia = ( posInicial + posFinal ) / 2;

            mergesort( arreglo, posInicial, posMedia );
            mergesort( arreglo, posMedia + 1, posFinal );
            merge( arreglo, posInicial, posMedia, posFinal ); // Mezcla A[posInicial..posMedia] y A[posMedia+1..posFinal]
        }
    }

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
        // En el pseudocódigo los arreglos siempre inician en 1 y terminan en n.
        // Ahora en la máquina los arreglos inician en 0 y terminan en n-1.
        // Ignoro si este pequeño cambio tiene implicaciones directas en las llamadas
        // a la parte izquierda y derecha de mergesort.
        mergesort( arreglo, 0, tamano - 1 );
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

