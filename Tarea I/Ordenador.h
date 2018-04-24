#ifndef _CLASE_ORDENADOR
#define _CLASE_ORDENADOR

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "time.h"

using namespace std;

class Ordenador {
private:

    // Ordenamiento por mezcla:

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

    // Ordenamiento por montículos.

    int inline padre (int i) { // Se calcula de esta forma el padre?
        return i / 2;
    };

    int inline hijoIzq (int i) {
        return (2 * i ) + 1;
    };

    int inline hijoDer (int i) {
        return (2 * i ) + 2;
    };

    void monticularizar (int * arreglo, int tamano) {

        int ultimoPadre = ( tamano - 1 ) / 2;
        for ( int k = ultimoPadre; k >= 0; --k ) // Corrige cimas comenzando con el último padre del árbol hasta el primero.
            corregirCima( arreglo, k, tamano );

    }

    void corregirCima (int * arreglo, int i, int tamMonticulo) {

        int posMaximo = 0; // Representa la posición en el arreglo del max{ A[ i, hijoIzq(i), hijoDer(i)] } ; "i" es la raíz del montículo.
        int posHijoIzq = hijoIzq( i );
        int posHijoDer = hijoDer( i );


        { // En resumen: determina la posición en el arreglo del elemento mayor entre un padre y sus dos hijos.

            if ( ( posHijoIzq <= tamMonticulo ) && ( arreglo[posHijoIzq] > arreglo[i] ) ) // Si la posicion del hijo izquierdo es menor que el tamaño del montículo y 
                // el hijo izquiero es más grande que el elemento en la raíz.
                posMaximo = posHijoIzq;
            else posMaximo = i;

            if ( ( posHijoDer <= tamMonticulo ) & ( arreglo[posHijoDer] > arreglo[posMaximo] ) ) // Si la posicion del hijo derecho es menor que el tamaño del montículo y 
                // el hijo derecho es más grande que el máximo.
                posMaximo = posHijoDer;
        }

        if ( posMaximo != i ) { // Implica que el padre es menor que sus hijos, por tanto hay que realizar un intercambio y volver a manipular el montículo, p
            // para que cumpla las propiedades de montículo.

            intercambiar( &arreglo[i], &arreglo[posMaximo] );
            corregirCima( arreglo, posMaximo, tamMonticulo );
        }
    }

    int extraerMaximo (int * arreglo, int tamMonticulo) {

        int maximo = arreglo[0];
        arreglo[0] = arreglo[tamMonticulo--];
        corregirCima( arreglo, 0, tamMonticulo );
        return maximo;
    }

    // Ordenamiento rápido:

    void quicksort (int * arreglo, int posInicial, int posFinal) {

        int pivote = 0;
        if ( posFinal > posInicial ) {
            pivote = particion( arreglo, posInicial, posFinal );
            quicksort( arreglo, posInicial, pivote-1);
            quicksort( arreglo, pivote + 1, posFinal );
        }
    }

    int particion (int * arreglo, int posInicial, int posFinal) {

        int pivote = arreglo[posFinal];
        int i = posInicial;
        int j = posFinal - 1;

        while ( i <= posFinal && i < j ) { // Mientras i no haya llegado al final -1 y j no se haya cruzado con i.

            // Nota: Si i se detiene es porque encontró un elemento menor al pivote, de lo anterior podemos conlcuir dos ideas; que
            // hay elementos menores al pivote antes de la i-ésima posición si y sólo si i no se detuvo en la posición que empezó.
            // Si i no se detuvo en la primera posición en la que empezó, garantiza que habrá intercambio con el elemento en la j-ésima posición.
            // De otra manera no habrá y j se decrementará hasta llegar a i.

            // Si i no se detiene y llega hasta el final, quiere decir que los elementos estaban ordenados con respecto al pivote.

            if ( arreglo[i] <= pivote ) { // Mientras el elemento en la i-ésima posición sea menor que el pivote, incrementamos i.
                ++i;
            } else {
                while ( i < j && ( arreglo[j] >= pivote ) ) { // Mientras j no haya llegado al inicio (Esto en el caso de que el i se haya detenido en la primera posición.)
                    // Y el elemento en la j-ésima posición sea mayor que el pivote, decrementamos j. La primera condición evita invadir posiciónes de memoria no válida.
                    --j;
                }// Se detuvo por dor razones: 1) Encontró un elemento menor al pivote. 2) j se cruzó con i.

                if ( arreglo[i] >= pivote && arreglo[j] <= pivote ) { // Luego de hacer el intercambio incrementamos i y decrementamos j y repetimos el proceso.
                    intercambiar( &arreglo[i++], &arreglo[j] );
                }
            }
        }

        intercambiar( &arreglo[i], &arreglo[posFinal] ); // Intercambia i con el pivote.

        return i; // Retorna el nuevo pivote.
    }

    // Otros:

    void intercambiar (int * a, int * b) {

        int temp = *a; // Almacenamos en el temporal, el dato en la memoria apuntada por a.
        *a = *b; // Almacenamos en la memoria apuntada por a, el dato almacenado en la memoria apuntada por b.
        *b = temp; // Almacenamos en la memoria apuntada por b, el dato temporal.
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
        mergesort( arreglo, 0, tamano - 1 );
    }

    void heapsort (int * arreglo, int tamano) {

        int i = tamano;
        int tamMonticulo = tamano;

        monticularizar( arreglo, tamano );

        while ( tamMonticulo )
            arreglo[i--] = extraerMaximo( arreglo, tamMonticulo-- );
    };

    void quicksort (int * arreglo, int tamano) {
        quicksort( arreglo, 0, tamano - 1 ); // Enviamos como posicion final del arreglo: n-1.
    };

    void radixsort (int * arreglo, int tamano) {
    };

    int mediana (int * arreglo, int tamano) {
    };
};
#endif

