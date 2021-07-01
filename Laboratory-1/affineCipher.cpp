/*  @brief affineCipher.cpp
*   This program encrypts a message using 
*   the Affine algorithm
*/

#include <bits/stdc++.h>
#include "files.h"
#include "processes.h"

using namespace std;

extern map<char, int> tableAlphabet;
extern string nameMessage;

void encryptAffine( string *message, string *key, string *alphabet ){

    char messageCipher[ (*message).size() ];
    int valueAandMi, finalValue;

    for( register int i = 0; i < (*message).size(); i++ ){
        valueAandMi = tableAlphabet.find( (*key)[0] )->second * tableAlphabet.find( (*message)[i] )->second;
        finalValue = ( valueAandMi + tableAlphabet.find( (*key)[1] )->second ) % (*alphabet).size();
        messageCipher[i] = (*alphabet)[ finalValue ];
    }

    messageCipher[ (*message).size() ] = '\0';

    //cout<< messageCipher;

    saveFile( messageCipher, ".aff", "Encrypt" );

}

void decryptAffine( string *message, string *key, string *alphabet ){

    int s, inverseNumber, gcdResult, numCharacter;
    char decryptMessage[ (*message).size() ];

    extendedEuclid( tableAlphabet.find( (*key)[0] )->second, (*alphabet).size(), &s, &inverseNumber, &gcdResult );

    for( register int i = 0; i < (*message).size(); i++ ){
        numCharacter = inverseNumber * ( tableAlphabet.find( (*message)[i] )->second + (*alphabet).size() - tableAlphabet.find( (*key)[1] )->second );
        numCharacter = numCharacter % (*alphabet).size();
        decryptMessage[i] = (*alphabet)[numCharacter];
    }

    decryptMessage[ (*message).size() ] = '\0';

    //cout<< decryptMessage;

    saveFile( decryptMessage, ".aff", "Decrypt" );

}
