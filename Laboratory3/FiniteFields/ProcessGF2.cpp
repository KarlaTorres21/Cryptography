/*  @brief G2.cpp
*   Programa que contiene las implementaciones
*   de las funciones contenidas en GF2.h
*/

#include <bits/stdc++.h>
#include "defs.h"

using namespace std;

void getPolynomial( int n, string *polynomialString ){

    ifstream filetoOpen;
    string read;
    register int contador = 0;

    filetoOpen.open( FILELIST, ios::in );

    if( filetoOpen.fail() ){
        cout<< "Error opening file";
        exit(EXIT_FAILURE);
    }

    while( getline( filetoOpen, read ) ) {
        if( contador == ( n - 3 ) ) 
            *polynomialString = read;
        contador++;
    }

    filetoOpen.close();
}

void getPowers( string polynomialString, bitset<9> *polynomialBits ){

    string auxString = "";

    for( register int i = 1; i < polynomialString.size() - 1; i++ )
        if( polynomialString[i] != ',' ){
            auxString = polynomialString[i];
            (*polynomialBits).set( stoi( auxString, nullptr, 10 ) );
            auxString = "";
        }
}

bitset<9> calMultiplication( int row, int column, int n, bitset<9> polynomialBits ){

    bitset<9> rowBits(row), columnBits(column);
    bitset<9> result;

    if( columnBits[0] == 1 )
        result = rowBits;

    for( register int i = 1; i < n; i++ ){
        rowBits = rowBits << 1;
        if( rowBits[n] == 1 )
            rowBits ^= polynomialBits;
        if( columnBits[i] == 1 )
            result ^= rowBits;
    }

    return result;
}
