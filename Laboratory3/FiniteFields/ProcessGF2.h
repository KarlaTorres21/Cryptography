/*  @brief GF2.h
*   Libreria que contiene todos los prototipos
*   de las funciones encargadas a realizar la
*   multiplicacion y guardado en el archivo de
*   salida
*/

#ifndef PROCESSGF2_H
#define PROCESSGF2_H

#include <bits/stdc++.h>

using namespace std;

void getPolynomial( int n, string *polynomialString );
void getPowers( string polynomialString, bitset<9> *polynomialBits );
bitset<9> calMultiplication( int row, int column, int n, bitset<9> polynomialBits );

#endif 