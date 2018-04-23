/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: dennis
 *
 * Created on 23 de abril de 2018, 11:32 AM
 */

#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include "Ordenador.h"

void imprimirArreglo(int * arreglo, int tamano);
void llenarArreglo(int * arreglo, int tamano);

using namespace std;

int main(int argc, char** argv)
{
    srand( time( NULL ) );

    int tamano = 25;
    Ordenador ordenador;

    /*{ // Ordenamiento por selección.

        int * arreglo = new int[tamano];
        llenarArreglo( arreglo, tamano );
        ordenador.seleccion( arreglo, tamano );
        delete[] arreglo;
    }*/

    /*{ // Ordenamiento por inserción.
        int * arreglo = new int[tamano];
        llenarArreglo( arreglo, tamano );
        ordenador.insercion( arreglo, tamano );
        delete[] arreglo;
    }*/

    { // Ordenamiento por mezcla.
        int * arreglo = new int[tamano];
        llenarArreglo( arreglo, tamano );
        ordenador.mergesort( arreglo, tamano );
        delete[] arreglo;
    }

    { // Ordenamiento por montículos.
        int * arreglo = new int[tamano];
        llenarArreglo( arreglo, tamano );

        std::cout << "Arreglo aleatorio" << std::endl << std::endl;
        imprimirArreglo( arreglo, tamano );


        ordenador.heapsort( arreglo, tamano );
        delete[] arreglo;
    }


    return 0;
}

void imprimirArreglo(int * arreglo, int tamano)
{
    for( int i = 0; i < tamano; ++i )
        std::cout << "[" << i << "] " << ": " << arreglo[i] << std::endl;
    std::cout << std::endl;
}

void llenarArreglo(int * arreglo, int tamano)
{
    for( int i = 0; i < tamano; ++i )
        arreglo[i] = ( rand( ) % 201 ) - ( 100 ); // Rango de aleatorios [-100, 100]

}

/*
std::cout << "Arreglo aleatorio" << std::endl << std::endl;
imprimirArreglo( arreglo, tamano );

std::cout << std::endl << "Arreglo ordenado" << std::endl << std::endl;
imprimirArreglo( arreglo, tamano );
 */