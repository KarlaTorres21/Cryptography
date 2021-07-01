/*  @brief PermutationCipher.cpp
*   Este programa realiza la operacion de permutacion
*   a nivel de caracter y a nivel de bits.
*/

#include <bits/stdc++.h>

using namespace std;


extern map<int, int> tablePermutation;

void encryptAndDecryptPermutation( string *contenttoEncrypt, string *finalText ){

    int position, bloque = 0;

    char *messagePrevious = new char[ (*contenttoEncrypt).size() ];
    for( register int i = 0; i < (*contenttoEncrypt).size(); i++ ){

        position = tablePermutation.find( ( i % tablePermutation.size() ) + 1  )->second;
        messagePrevious[ position - 1 + bloque ]  = (*contenttoEncrypt)[ i ];

        if( ( i != 0 ) && ( ( i + 1) % tablePermutation.size()  == 0 ) )
            bloque = bloque + tablePermutation.size();
            
    }

    messagePrevious[ (*contenttoEncrypt).size() ] = '\0';
    (*finalText) = messagePrevious;
    cout<< " El mensaje cifrado es: " << *finalText << endl;

    delete[] messagePrevious; 

}


void encAndDecBinaryMode( string *contenttoEncrypt, string nameToSave ){

    int bloque = 0, numCharacters = tablePermutation.size() / 8;
    long int numByteI, numBitI, position, numByteJ, numBitJ, onOrOff;
    unsigned char copy[ (*contenttoEncrypt).size() ];
    string contentCopy = *contenttoEncrypt, message = "", toWork, modify;

    for( register int i = 0; i < (*contenttoEncrypt).size(); i += numCharacters ){

        toWork = contentCopy.substr( i, numCharacters );
        modify = toWork;

        for( register int j = 0; j < ( numCharacters * 8 ); j++ ){

            position = tablePermutation.find( ( j % tablePermutation.size() ) + 1  )->second - 1;

            numByteI = j >> 3;
            numBitI = j & 7;

            numByteJ = position >> 3;
            numBitJ = position & 7;

            if(  ( modify[numByteI] & ( 1 << numBitI ) ) == 0 )
                toWork[numByteJ] &= ~( 1 << numBitJ  );
    
            else
                toWork[numByteJ] |= ( 1 << numBitJ );        

        }

        message = message + toWork;
    }

    message[ (*contenttoEncrypt).size() ] = '\0';

    cout<< message <<endl;
    freopen( nameToSave.c_str() , "w", stdout );
    cout<< message;
    fclose(stdout);

}
