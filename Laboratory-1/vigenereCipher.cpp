/*  @brief vigenereCipher.cpp
*   This program encrypts a message using 
*   the Vigenere algorithm
*/

#include <bits/stdc++.h>
#include "files.h"
#include "processes.h"

extern map<char, int> tableAlphabet;

using namespace std;

void encryptVigenere( string *message, string *key, string *alphabet ){

    int numCharacter, modMessageandKey;
    char messageCipher[ (*message).size() ];

    for( register int i = 0; i < (*message).size(); i++ ){
         numCharacter = ( tableAlphabet.find( (*message)[i] )->second + tableAlphabet.find( (*key)[i%(*key).size()] )->second ) % (*alphabet).size();
         messageCipher[i] = (*alphabet)[numCharacter];
    }

    messageCipher[ (*message).size() + 1 ] = '\0';

    saveFile( messageCipher,".vig", "Encrypt" );

}

void decryptVigenere( string *message, string *key, string *alphabet ){

    int numCharacter, modMessageandKey;
    char decryptMessage[ (*message).size() ];

    for( register int i = 0; i < (*message).size(); i++ ){
        numCharacter = ( tableAlphabet.find( (*message)[i] )->second - tableAlphabet.find( (*key)[i%(*key).size()] )->second );
        if( numCharacter < 0 )
            negativeNumbMod( &numCharacter, (*alphabet).size() );
        else 
            numCharacter = numCharacter % (*alphabet).size();
        decryptMessage[i] = (*alphabet)[numCharacter];
    }

    decryptMessage[ (*message).size() + 1 ] = '\0';

    saveFile( decryptMessage, ".vig", "Decrypt" );

}
