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

    int tamano = 100000;
    Ordenador ordenador;

    { // Ordenamiento por selección.

        int * arregloSeleccion = new int[tamano];
        llenarArreglo( arregloSeleccion, tamano );
        ordenador.seleccion( arregloSeleccion, tamano );
        delete[] arregloSeleccion;
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