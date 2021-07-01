#include <bits/stdc++.h>
#include "askValues.h"
#include "vigenereCipher.h"
#include "files.h"
#include "affineCipher.h"

using namespace std;

// Variable global
map<char, int> tableAlphabet;
string nameMessage;

int mainMenu( void );

int main(){

    int option = mainMenu();
    string message, key, alphabet;
    system("cls"); 

    switch (option){
    case 1:
        cout<< "\t \t Encrypt Vigenere Cipher" << endl;
        askforKeyandFilesName( "Vigenere", "Encrypt", &message, &key, &alphabet );
        encryptVigenere( &message, &key, &alphabet );
        break;
    case 2:
        cout<< "\t \t Decrypt Vigenere Cipher" << endl;
        askforKeyandFilesName( "Vigenere", "Decrypt", &message, &key, &alphabet );
        decryptVigenere( &message, &key, &alphabet );
        break;
    case 3:
        cout<< "\t \t Verify if a candidate key for affine cipher is valid key" << endl;
        askforKeyAffine( &alphabet );
        break;
    case 4:
        cout<< "\t \t Calculate inverse a mod n " << endl;
        askforNumberInverse( );
        break;
    case 5:
        cout<< "\t \t Encrypt Affine Cipher" << endl;
        askforKeyandFilesName( "Affine", "Encrypt", &message, &key, &alphabet );
        encryptAffine( &message, &key, &alphabet );
        break;
    case 6: 
        cout<< "\t \t Decrypt Affine Cipher" << endl;
        askforKeyandFilesName( "Affine", "Decrypt", &message, &key, &alphabet );
        decryptAffine( &message, &key, &alphabet );
        break;
    default:
        cout<< "Invalid option";
        break;
    }

}

int mainMenu( void ){

    int option;

    cout<< "\t What do you want to do? " << endl;
    cout<< " 1. Encrypt Vigenere Cipher" << endl;
    cout<< " 2. Decrypt Vigenere Cipher" << endl;
    cout<< " 3. Verify if a candidate key for affine cipher is valid key" << endl;
    cout<< " 4. Calculate inverse a mod n" << endl;
    cout<< " 5. Encrypt Affine Cipher" << endl;
    cout<< " 6. Decrypt Affine Cipher" << endl;
    cout<< " Select an option: ";
    cin>> option;

    return option;

}