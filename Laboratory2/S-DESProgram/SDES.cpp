/*  @brief SDES.c
*   Implementacion de las funciones encontradas
*   en la libreria SDES, este programa hace uso
*   de las funciones encontradas en ProcessSDES.h
*/

#include <bits/stdc++.h>
#include "TransformKey.h"
#include "ProcessSDES.h"

using namespace std;

void KeysGenerateSDES( bitset<10> *binaryKey, bitset<8> *subKey1, bitset<8> *subKey2, int ifGenerateorNot ){
    
    string key = "", nameofFileKey;

    if( ifGenerateorNot ){
        generateKey( &key );
        saveKeytoFile( key );
    }

    else{
        cout<< " Key file: ";
        cin>> nameofFileKey;
        obtainContentKey( "./Archivos/" + nameofFileKey, &key );
    }

    (*binaryKey) = bitset<10>( key );
    applyPermutation10( binaryKey );
    applyShiftSubKeys( binaryKey, 1 );
    applyPermutation8( binaryKey, subKey1 );
    applyShiftSubKeys( binaryKey, 2 );
    applyPermutation8( binaryKey, subKey2 );

}

void EncryptSDES( char *messagetoEncrypt, bitset<8> subKey1, bitset<8> subKey2, string nametoFile ){

    applyPermutationIP( messagetoEncrypt );
    roundOne( messagetoEncrypt, subKey1, subKey2, "Encrypt" );

}

void DecryptSDES( char *messagetoEncrypt, bitset<8> subKey1, bitset<8> subKey2, string nametoFile ){

    applyPermutationIP( messagetoEncrypt );
    roundOne( messagetoEncrypt, subKey1, subKey2, "Decrypt" );

}
