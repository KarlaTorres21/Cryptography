/*  @brief Files.cpp
*   This program get contents of the files and
*   save it in a variable and write content to 
*   text files
*/

#include <bits/stdc++.h>

using namespace std;

extern map<int, int> tablePermutation;

void obtainTable( string nameFile, string *valueofPhi ){

    ifstream filetoOpen;
    string message;
    register int contador = 0;

    filetoOpen.open( nameFile.c_str(), ios::in );

    if( filetoOpen.fail() ){
        cout<< "Error opening file";
        exit(EXIT_FAILURE);
    }

    while( getline( filetoOpen, message ) ) {
        if( contador == 1 )
            *valueofPhi = message;
        contador++;
    }

    filetoOpen.close();
}   

void writetoFile( string nameofFile ){

    ofstream filePermutation;
    map<int, int>::iterator itr; 
    filePermutation.open( nameofFile.c_str(), ios :: out );

    if( filePermutation.fail() ){
        cout<< "Error writing the generated key";
        exit( EXIT_FAILURE );
    }

    for (itr = tablePermutation.begin(); itr != tablePermutation.end(); ++itr) { 
        filePermutation<< itr->first; 
        filePermutation<< " ";
    } 

    filePermutation<< "\n";

    for (itr = tablePermutation.begin(); itr != tablePermutation.end(); ++itr) { 
        filePermutation<< itr->second; 
        filePermutation<< " ";
    } 

    filePermutation.close();

}

void writePermutation( string nameofFile, vector<int> *values ){

    ofstream filetoSave;
    filetoSave.open( nameofFile.c_str(), ios :: out );

    if( filetoSave.fail() ){
        cout<< "Error writing the generated key";
        exit( EXIT_FAILURE );
    }

    for ( register int i = 0; i < (*values).size() ; i++ ) { 
        filetoSave<< i+1; 
        filetoSave<< " ";
    } 

    filetoSave<< "\n";

    for ( register int i = 0; i < (*values).size() ; i++ ) { 
        filetoSave<< (*values)[i]; 
        filetoSave<< " ";
    } 

    filetoSave.close();

}

void obtainText( string nameFile, string *fileContent ){

    ifstream filetoEncrypt;
    string content;

    filetoEncrypt.open( nameFile.c_str(), ios::binary );

    if( filetoEncrypt.fail() ){
        cout<< "Error opening file";
        exit(EXIT_FAILURE);
    }

    while( !filetoEncrypt.eof() ){
        getline( filetoEncrypt, content );
        *fileContent = *fileContent + content;
    }

    filetoEncrypt.close();

}

void writeMessage( string *contenttoWrite, string nametoSave ){

    ofstream filetoSave;
    filetoSave.open( nametoSave.c_str(), ios :: binary );

    if( filetoSave.fail() ){
        cout<< "Error writing the generated key";
        exit( EXIT_FAILURE );
    }

    filetoSave<< *contenttoWrite;

    filetoSave.close();

}
