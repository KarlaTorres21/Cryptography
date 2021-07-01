/*  @brief KeySchedule.cpp
*   Programa que contiene la implementacion de
*   la funcion encargada de encontrar las 12
*   subclaves de AES de 192 bits
*/

#include <bits/stdc++.h>
#include "KeyScheduleProcess.h"
#include "defs.h"

using namespace std;

void KeyScheduleAES( string nameFile ){
    string keyString, nametoSave;
    bitset<8> W[4][6], T[4][1], leftOver[4][2];

    nametoSave = FINALFILE + nameFile;

    getKey( nameFile, &keyString );
    keyBit( keyString, W );

    freopen( nametoSave.c_str() , "w", stdout );

    for( register int i = 1; i <= 8; i++ ){
        if( ( i % 2 ) != 0 )
            saveValues( W, leftOver );
        RotBytes( W, T );
        SubBytes( T );
        XorRC( T, i );
        modifyValues( T, W );
        imprimirMatriz( W, i, leftOver );
        cout<< "\n";
    }

    fclose(stdout);
}
