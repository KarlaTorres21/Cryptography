/*  @brief ProcessCFB.c
*   Implementacion de las operaciones realizadas
*   para el modo de operacion CFB
*/

#include <bits/stdc++.h>
#include "SDES.h"

using namespace std;

void vectorIVGeneration( string *vectorIV ){

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(0,1);

    for ( size_t i = 0; i < 8; i++ )
        *vectorIV = (*vectorIV) + to_string( distribution(generator));

    //*vectorIV = "10111101";
}

void saveVectorIV( string vectorIV ){
    ofstream filetoSave;
    filetoSave.open( "./Archivos/IV-CFBMode.txt", ios :: binary );

    if( filetoSave.fail() ){
        cout<< "Error writing the generated key";
        exit( EXIT_FAILURE );
    }

    filetoSave<< vectorIV;

    filetoSave.close();
}

void getIV( string *IV, string nameFile ){

    ifstream filetoOpen;
    string content;

    filetoOpen.open( nameFile.c_str(), ios::in );

    if( filetoOpen.fail() ){
        cout<< "Error opening file";
        exit(EXIT_FAILURE);
    }

    while( !filetoOpen.eof() ){
        getline( filetoOpen, *IV );
    }

    filetoOpen.close();

}
