/*  @brief main.c
*   Archivo que contiene el programa principal, en el cual
*   se mandan llamar a las demas funciones
*/

#include <bits/stdc++.h>
#include <cstdlib> 
#include "Files.h"
#include "Process.h"
#include "PermutationCipher.h"

using namespace std;

// Variable global
map<int, int> tablePermutation;

int mainMenu( void );

int main(){

    int option = mainMenu();
    int permutationValue;
    string nameofFile, valueofPhi, nameFilePermutation, nametoEncrypt;
    string fileContent = "", messageEncrypt;
    vector<int> randomNumbers;
    system("cls"); 
    map<int, int>::iterator itr; 

    switch (option){
    case 1:
        cout<< "\t \t Calculate inverse permutation" << endl;
        cout<< " Permutation table file: ";
        cin>> nameofFile;
        obtainTable( "./Archivos/" + nameofFile, &valueofPhi );
        inversePermutation( &valueofPhi );
        writetoFile( "./Archivos/Inverse" + nameofFile );
        break;
    case 2:
        cout<< "\t \t Generate random permutation" << endl;
        cout<< " Permutation value: ";
        cin>> permutationValue;
        cout<< " File name to save: ";
        cin>> nameFilePermutation;
        randomNumbers = randomPermutation( permutationValue );
        writePermutation( "./Archivos/" + nameFilePermutation, &randomNumbers );
        break;
    case 3:
        cout<< "\t \t Encrypt Permutation Cipher" << endl;
        cout<< " File name to Encrypt: ";
        cin>> nametoEncrypt;
        obtainText( "./Archivos/" + nametoEncrypt, &fileContent );
        cout<< " File name to Permutation: ";
        cin>> nameFilePermutation;
        obtainTable( "./Archivos/" + nameFilePermutation, &valueofPhi );
        mappingValues( &valueofPhi );
        if( askforType( ).compare( "Yes" ) ){
            verifytoMod( &fileContent );
            encryptAndDecryptPermutation( &fileContent, &messageEncrypt );
            writeMessage( &messageEncrypt, "./Archivos/Enc" + nametoEncrypt );
        }
        else{
            reviewMod( &fileContent );
            encAndDecBinaryMode( &fileContent, "./Archivos/Enc" + nametoEncrypt );
        }
        break;
    case 4:
        cout<< "\t \t Decrypt Permutation Cipher" << endl;
        cout<< " File name to Decrypt: ";
        cin>> nametoEncrypt;
        cout<< " File name to Permutation: ";
        cin>> nameFilePermutation;
        obtainTable( "./Archivos/" + nameFilePermutation, &valueofPhi );
        inversePermutation( &valueofPhi );
        writetoFile( "./Archivos/Inverse" + nameFilePermutation );
        obtainText( "./Archivos/" + nametoEncrypt, &fileContent );
        if( askforType( ).compare( "Yes" ) ){
            encryptAndDecryptPermutation( &fileContent, &messageEncrypt );
            writeMessage( &messageEncrypt, "./Archivos/Dec" + nametoEncrypt );
        }
        else{
            encAndDecBinaryMode( &fileContent, "./Archivos/Dec" + nametoEncrypt );
        }
        break;
    default:
        cout<< "Invalid option";
        break;
    }

}

int mainMenu( void ){

    int option;

    cout<< "\t What do you want to do? " << endl;
    cout<< " 1. Calculate inverse permutation" << endl;
    cout<< " 2. Generate random permutation" << endl;
    cout<< " 3. Encrypt Permutation Cipher" << endl;
    cout<< " 4. Decrypt Permutation Cipher" << endl;
    cout<< " Select an option: ";
    cin>> option;

    return option;

}
