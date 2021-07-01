/*  @brief processes.cpp
*   This program performs intermediate tasks 
*   such as alphabet maping, key generation, etc.
*/

#include <bits/stdc++.h>
#include "files.h"

extern map<char, int> tableAlphabet;

using namespace std;

void mapeoAlphabet( string *alphabet ){

    for( register int i = 0; i < (*alphabet).size() ; i++ )
        tableAlphabet.insert( pair<char, int>( (*alphabet)[i], i ));

}

void negativeNumbMod( int *modifyModule, int sizeAlphabet ){
    *modifyModule = sizeAlphabet - ( (-*modifyModule) % sizeAlphabet );
}

int verifyAffineKey( int sizeAlphabet, int a ){
    if( __gcd( a, sizeAlphabet ) == 1 )
        return 1;
    else
        return 0;
}

void generateKeyVigenere( string *key, string *message, string *alphabet ){

    //limite_inferior + rand() % (limite_superior +1 - limite_inferior)
    int sizeKey = 5 + rand() % ( 15 + 1 - 5 ), contKey;
    char keyPrevious[ sizeKey ];
    srand( getpid() );

    for( register int i = 0; i < sizeKey; i++ ){
            contKey = rand() % (*alphabet).size();
            keyPrevious[i] = (*alphabet)[contKey];
    }

    keyPrevious[sizeKey] = '\0';

    *key = keyPrevious;

    cout<< "La llave generada fue: " << *key << endl;

    writeKeytoFile( "Vigenere", key );

}

void generateKeyAffine( string *key, string *alphabet ){

    srand( getpid() );
    int a = 1 + rand() % ( (*alphabet).size() - 1 ), b = 2 + rand() % ( (*alphabet).size() - 1 );
    int correctKey = verifyAffineKey( (*alphabet).size(), a );
    char keyPrevious[2];

    while( correctKey == 0 ){
        a = 2 + rand() % ( (*alphabet).size() - 1 );
        correctKey = verifyAffineKey( (*alphabet).size(), a );
    }
    keyPrevious[0] = (*alphabet)[a]; keyPrevious[1] = (*alphabet)[b]; keyPrevious[2] = '\0';

    cout<< "gcd( " << a << ", " << (*alphabet).size() << " ) -> Ek = ( "<< a << ", " << b << " )" << endl;

    *key = keyPrevious;
    writeKeytoFile( "Affine", key );

}

void extendedEuclid( int valueofA, int valueofN, int *s, int *t, int *gcdResult ){

    int s0 = 1, s1 = 0, t0 = 0, t1 = 1, residue, quotient, sizeAlphabet = valueofN;

    if( valueofA == 0 ){
        *gcdResult = 0;
        *s = 1;
        *t = 0; 
        return;
    } 

    while( valueofA != 0 ){

        residue = valueofN % valueofA;
        quotient = ( valueofN - residue ) / valueofA;
        *s = s0 - ( quotient * s1 );
        *t = t0 - ( quotient * t1 );
        valueofN = valueofA;
        valueofA = residue;
        s0 = s1;
        s1 = *s;
        t0 = t1;
        t1 = *t;

    }

    if( s0 < 0 )
        negativeNumbMod( &s0, sizeAlphabet );

    if( t0 < 0 )
        negativeNumbMod( &t0, sizeAlphabet );

    *gcdResult = valueofN;
    *s = s0;
    *t = t0;
    return;

}
