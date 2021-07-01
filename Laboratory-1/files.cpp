/*  @brief askValues.c
*   This program get contents of the files and
*   save it in a variable
*/

#include <bits/stdc++.h>

using namespace std;

extern string nameMessage;

void obtainContent( string nameFile, string *vartoSave, string *nameWithoutExtension ){

    ifstream filetoOpen;
    int txtPosicion;

    filetoOpen.open( nameFile.c_str(), ios::in );

    if( filetoOpen.fail() ){
        cout<< "Error opening file";
        exit(EXIT_FAILURE);
    }

    txtPosicion = nameFile.find( ".txt" ) + 4;
    *nameWithoutExtension = nameFile.substr(0, txtPosicion);
    
    while( !filetoOpen.eof() )
        getline( filetoOpen, *vartoSave );

    filetoOpen.close();

}

void writeKeytoFile( string typeCipher, string *key ){

    ofstream fileGenerate;
    string nameFile = "KeyGenerate" + typeCipher + ".txt";
    fileGenerate.open( nameFile.c_str(), ios :: out );

    if( fileGenerate.fail() ){
        cout<< "Error writing the generated key";
        exit( EXIT_FAILURE );
    }

    fileGenerate<< *key;
    fileGenerate.close();

}

void saveFile( string texttoSave, string typeCipher, string operationtoDo ){

    ofstream fileEncrypt;
    string nametoSave = nameMessage + typeCipher;

    if( !(operationtoDo.compare("Decrypt")) )
        nametoSave = operationtoDo + nameMessage + typeCipher;

    fileEncrypt.open( nametoSave.c_str() , ios :: out );

    if( fileEncrypt.fail() ){
        cout<< "Error writing the generated key";
        exit( EXIT_FAILURE );
    }

    fileEncrypt<< texttoSave;
    fileEncrypt.close();

}
