/*  @brief askValues.cpp
*   This program asks the user the data to use to
*   perform the selected action
*/

#include <bits/stdc++.h>
#include "files.h"
#include "processes.h"

using namespace std;

extern string nameMessage;

void askforKeyandFilesName( string typeChiper, string actiontoDo, string *message, string *key, string *alphabet ){

    string responseKey, nameAlphabet, nameKey, auxName;
    string nameWithoutExtension;

    if( actiontoDo.compare("Encrypt") == 0 ){
        cout<< " Do you want a randomly key? ";
        cin>> responseKey;
    }

    cout<< " Alphabet File Name: ";
    cin>> nameAlphabet;
    obtainContent( nameAlphabet, alphabet, &nameWithoutExtension );
    mapeoAlphabet( alphabet );

    cout<< " Input File Name: ";
    cin>> nameMessage;
    obtainContent( nameMessage, message, &nameWithoutExtension );
    auxName = nameWithoutExtension;

    if( responseKey.compare("Yes") || actiontoDo.compare("Decrypt") == 0 ){
        cout<< " Key File Name: ";
        cin>> nameKey;
        obtainContent( nameKey, key, &nameWithoutExtension );
        //nameMessage = nameWithoutExtension;
    }
    else{
        if( !( typeChiper.compare("Vigenere") ) )
            generateKeyVigenere( key, message, alphabet );
        else 
            generateKeyAffine( key, alphabet );
    }

    nameMessage = auxName;

}

void askforKeyAffine( string *alphabet ){

    ifstream filetoOpen;
    string responseKey;
    int sizeAlphabet, a, b;

    cout<< " Do you know the size of the alphabet? ";
    cin>> responseKey;

    if( !responseKey.compare("Yes") ){
        cout<< " Alphabet size: ";
        cin>> sizeAlphabet;
    }

    else{
        cout<< " Alphabet File Name: ";
        cin>> responseKey;
        filetoOpen.open( responseKey.c_str(), ios::in );

        while( !filetoOpen.eof() )
            getline(filetoOpen, *alphabet);

        filetoOpen.close();
    
        sizeAlphabet = (*alphabet).size();
        cout<< " Alphabet size is: " <<sizeAlphabet <<endl;
    }

    cout<< " Enter a and b: ";
    cin>> a; 
    cin>> b;

    if( verifyAffineKey( sizeAlphabet, a ) )
        cout<< " Candidate key is a valid key";
    else 
        cout<< " Candidate key is an invalid key";

}

void askforNumberInverse( void ){

    int valueofA, valueofB, valueofN, response, s, t, gcdResult;

    cout<< " Enter the value of a: ";
    cin>> valueofA;

    cout<< " Enter the value of b: ";
    cin>> valueofB;

    cout<< " Enter the value of n: ";
    cin>> valueofN;

    extendedEuclid( valueofA, valueofN, &s, &t, &gcdResult );

    cout<< " The inverse of " << valueofA << " mod " << valueofN << " is: " << t;
    
}
