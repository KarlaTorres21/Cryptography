/*  @brief KeySchedule.cpp
*   Programa que contiene la implementacion de
*   la funcion encargada de encontrar las 10
*   subclaves de AES de 129 bits
*/

#include <bits/stdc++.h>
#include "KeyScheduleProcess.h"
#include "defs.h"

using namespace std;

void KeyScheduleAES( string nameFile ){
    string keyString, nametoSave;
    bitset<8> W[4][4], T[4][1];

    nametoSave = FINALFILE + nameFile;

    getKey( nameFile, &keyString );
    keyBit( keyString, W );

    freopen( nametoSave.c_str() , "w", stdout );

    for( register int i = 1; i <= 10; i++ ){
        RotBytes( W, T );
        SubBytes( T );
        XorRC( T, i );
        modifyValues( T, W );
        imprimirMatriz( W );
        cout<< "\n";
    }

    fclose(stdout);
}
