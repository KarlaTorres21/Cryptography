/*  @brief main.c
*   Archivo que hace uso del cifrado SDES
*/

#include <bits/stdc++.h>
#include <cstdlib> 
#include "Files.h"
#include "SDES.h"

using namespace std;

int mainMenu( void );

int main(){

    int option = mainMenu();
    string nameofFileKey, valueKey, nametoFile, contentText, messageEncrypt = "", nametoSave;
    bitset<10> binaryKey, P10Key1, P10Key2;
    bitset<8> subKey1, subKey2;
    bitset<1> messageBinary;
    system("cls"); 

    switch (option){
    case 1:
        cout<< "\t \t Encrypt S-DES" << endl;
        cout<< " File to encrypt: ";
        cin>> nametoFile;
        obtainContentText( "./Archivos/" + nametoFile, &contentText );
        
        KeysGenerateSDES( &binaryKey, &subKey1, &subKey2, 1 );
        cout<< "Subllave 1: " << subKey1 << endl;
        cout<< "Subllave 2: " << subKey2 << endl;

        for( register int i = 0; i < contentText.size(); i++ ){
            EncryptSDES( &contentText[i], subKey1, subKey2, nametoFile );
            messageEncrypt = messageEncrypt + contentText[i];
        }

        nametoSave = "./Archivos/Enc" + nametoFile;
        freopen( nametoSave.c_str() , "w", stdout );
        cout<< messageEncrypt;
        fclose(stdout);

        break;
    case 2:
        cout<< "\t \t Decrypt S-DES" << endl;
        cout<< " File to encrypt: ";
        cin>> nametoFile;
        obtainContentText( "./Archivos/" + nametoFile, &contentText );

        KeysGenerateSDES( &binaryKey, &subKey1, &subKey2, 0 );
        cout<< "Subllave 1: " << subKey1 << endl;
        cout<< "Subllave 2: " << subKey2 << endl;

        for( register int i = 0; i < contentText.size(); i++ ){
            DecryptSDES( &contentText[i], subKey1, subKey2, nametoFile );
            messageEncrypt = messageEncrypt + contentText[i];
        }

        nametoSave = "./Archivos/Dec" + nametoFile;
        freopen( nametoSave.c_str() , "wb", stdout );
        cout<< messageEncrypt;
        fclose(stdout);
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