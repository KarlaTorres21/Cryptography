/*  @brief KeyGeneration.cpp
*   Implementacion de las funciones necesarias para 
*   obtener la llave principal y las subclaves
*/

#include <bits/stdc++.h>

using namespace std;

void generateKey( string *key ){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(0,1);

    for ( size_t i = 0; i < 10; i++ )
        *key = (*key) + to_string( distribution(generator));

    //*key = "1010000010";
}

void saveKeytoFile( string key ){

    ofstream filetoSave;
    filetoSave.open( "./Archivos/KeyS-DES.txt", ios :: out );

    if( filetoSave.fail() ){
        cout<< "Error writing the generated key";
        exit( EXIT_FAILURE );
    }

    filetoSave<< key;

    filetoSave.close();
}

void obtainContentKey( string nameFile, string *key ){

    ifstream filetoOpen;
    string content;

    filetoOpen.open( nameFile.c_str(), ios::in );

    if( filetoOpen.fail() ){
        cout<< "Error opening file";
        exit(EXIT_FAILURE);
    }

    while( !filetoOpen.eof() ){
        getline( filetoOpen, *key );
    }

    filetoOpen.close();

}

void applyPermutation10( bitset<10> *binaryKey ){

    int P10[ 10 ] = {5, 3, 2, 10, 1, 7, 4, 9, 6, 8};
    bitset<10> copy = *binaryKey;

    for( register int i = 0; i < 10; i++ )
        (*binaryKey)[i] = copy[ P10[i] - 1 ];

}

void applyShiftSubKeys( bitset<10> *binaryKey, int numberShift ){

    bitset<5> blockLeft, blockRigth;
    int valueLeft[numberShift], valueRigth[numberShift];
    register int j = 0;

    for( register int i = 0; i < 5; i++ ){
        blockRigth[i] = (*binaryKey)[i];
        blockLeft[i] = (*binaryKey)[i+5]; 
    }

    for( register int i = 0; i < numberShift; i++ ){
        valueLeft[i] = blockLeft[4-i];
        valueRigth[i] = blockRigth[4-i];
    }

    blockLeft <<= numberShift;
    blockRigth <<= numberShift;

    if( numberShift == 1 ){
        blockLeft[0] = valueLeft[0];
        blockRigth[0] = valueRigth[0];
    }

    else{
        blockLeft[0] = valueLeft[1];        blockLeft[1] = valueLeft[0];
        blockRigth[0] = valueRigth[1];      blockRigth[1] = valueRigth[0];
    }

    for( register int i = 0; i < 5; i++ ){
        (*binaryKey)[i] = blockRigth[i];
        (*binaryKey)[i+5] = blockLeft[i];
    }
}

void applyPermutation8( bitset<10> *binaryKey, bitset<8> *subKey ){

    int P8[ 8 ] = {1, 2, 6, 3, 7, 4, 8, 5};

    for( register int i = 0; i < 8; i++ )
        (*subKey)[i] = (*binaryKey)[ P8[i] - 1 ];

}
