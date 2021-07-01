/*  @brief main.c
*   Archivo que hace uso del cifrado SDES
*/

#include <bits/stdc++.h>
#include <cstdlib> 
#include "Files.h"
#include "ModeCFB.h"

using namespace std;

int mainMenu( void );

int main(){

    int option = mainMenu();
    string nameofFileKey, valueKey, nametoFile, contentText, messageEncrypt = "", nametoSave;
    bitset<10> binaryKey;
    bitset<8> subKey1, subKey2;
    bitset<1> messageBinary;
    system("cls"); 

    switch (option){
    case 1:
        cout<< "\t \t Encrypt Mode of Operation: CFB" << endl;
        cout<< " File to encrypt: ";
        cin>> nametoFile;
        obtainContentText( "./Archivos/" + nametoFile, &contentText );
        modeOfOperationCFBCipher( &contentText, nametoFile );
        break;

    case 2:
        cout<< "\t \t Decrypt Mode of Operation: CFB" << endl;
        cout<< " File to encrypt: ";
        cin>> nametoFile;
        obtainContentText( "./Archivos/" + nametoFile, &contentText );
        modeOfOperationCFBDecrypt( &contentText, nametoFile );
        break;
    default:
        cout<< "Invalid option";
        break;
    }

}

int mainMenu( void ){

    int option;

    cout<< "\t What do you want to do? " << endl;
    cout<< " 1. Encrypt S-DES" << endl;
    cout<< " 2. Decrypt S-DES" << endl;
    cout<< " Select an option: ";
    cin>> option;

    return option;

}