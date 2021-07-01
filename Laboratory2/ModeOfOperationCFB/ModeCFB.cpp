/*  @brief ModeCFB.c
*   Implementacion del modo de operacion CFB
*   haciendo uso de la biblioteca SDES
*/

#include <bits/stdc++.h>
#include "SDES.h"
#include "ProcessCFB.h"
#include "ModeCFB.h"

using namespace std;

void modeOfOperationCFBCipher( string *contentText, string nameFile ){

    string vectorIV, messageEncrypt = "", nametoSave;
    char inputSDES, outputCFB;

    bitset<10> binaryKey;
    bitset<8> subKey1, subKey2, valueBinary;

    vectorIVGeneration( &vectorIV );
    saveVectorIV( vectorIV );
    KeysGenerateSDES( &binaryKey, &subKey1, &subKey2, 1 );

    inputSDES = static_cast<char>( bitset<8>( vectorIV ).to_ulong() );

    for( register int i = 0; i < (*contentText).size(); i++ ){
        EncryptSDES( &inputSDES, subKey1, subKey2 );
        outputCFB = inputSDES ^ (*contentText)[i];
        inputSDES = outputCFB;
        messageEncrypt = messageEncrypt + outputCFB;
    }
    
    nametoSave = "./Archivos/Enc" + nameFile;
    freopen( nametoSave.c_str() , "w", stdout );
    cout<< messageEncrypt;
    fclose(stdout);

}

void modeOfOperationCFBDecrypt( string *contentText, string nameFile ){

    string vectorIV, messageEncrypt = "", nametoSave, nameIV;
    char inputSDES, plaintext, outputSDES;

    bitset<10> binaryKey;
    bitset<8> subKey1, subKey2, valueBinary;

    cout<<" File IV: ";
    cin>> nameIV;
    getIV( &vectorIV, "./Archivos/" + nameIV );

    KeysGenerateSDES( &binaryKey, &subKey1, &subKey2, 0 );

    inputSDES = static_cast<char>( bitset<8>( vectorIV ).to_ulong() );

    for( register int i = 0; i < (*contentText).size(); i++ ){
        EncryptSDES( &inputSDES, subKey1, subKey2 );
        outputSDES = inputSDES ^ (*contentText)[i];
        inputSDES = (*contentText)[i];
        messageEncrypt = messageEncrypt + outputSDES;
    }
    
    nametoSave = "./Archivos/Dec" + nameFile;
    freopen( nametoSave.c_str() , "w", stdout );
    cout<< messageEncrypt;
    fclose(stdout);

}
