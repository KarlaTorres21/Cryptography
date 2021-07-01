/*  @brief G2.cpp
*   Programa que contiene la implementacion de
*   la funcion encargada de encontrar GF2, para 
*   esto se hace uso de la liberia ProcessGF2.h
*/

#include <bits/stdc++.h>
#include "ProcessGF2.h"
#include "defs.h"

using namespace std;

void calculateGF2( int n, string saveMode ){

    string polynomialString;
    int posibilities = 1 << n, bitSet, cont = 0;
    bitset<9> polynomialBits, result, result1, result2, result3;
    string nameFile;

    if( saveMode.compare( "Yes" ) )
        nameFile = SAVEDFILEHEX + to_string(n) + ".txt";

    else 
        nameFile = SAVEDFILEPOL + to_string(n) + ".txt";

    //freopen( nameFile.c_str() , "w", stdout );

    getPolynomial( n, &polynomialString );
    getPowers( polynomialString, &polynomialBits );

    result = calMultiplication( 3, 99, n, polynomialBits );
    cout<< hex << uppercase << result.to_ulong() <<endl;

    result1 = calMultiplication( 1, 99, n, polynomialBits );
    cout<< hex << uppercase << result1.to_ulong()<<endl;

    result2 = calMultiplication( 1, 99, n, polynomialBits );
    cout<< hex << uppercase << result2.to_ulong()<<endl;

    result3 = calMultiplication( 2, 99, n, polynomialBits );
    cout<< hex << uppercase << result3.to_ulong()<<endl;

    cout<< hex <<uppercase << (result^result1^result2^result3).to_ulong();

    /*for( register int i = 1; i < posibilities; i++ ){
        for( register int j = 1; j < posibilities; j++ ){
            result = calMultiplication( i, j, n, polynomialBits );
            if( saveMode.compare( "Yes" ) ){
                cout<< hex << uppercase << result.to_ulong();
                cout<< "  ";
            }
            else{
                cont = 0;
                cout<< "(";
                bitSet = result.count();
                for( register int k = 0; k < n; k++ ){
                    if( result[k] == 1 ){
                        cout<< k;
                        cont++;
                    }
                    if( cont == bitSet )
                        break;
                    if( result[k] == 1 ){
                        cout<< ",";
                    }
                }
                cout<< ") ";
            }
        }
        cout<< "\n";
    }

    fclose(stdout);*/
}
