/*  @brief Files.cpp
*   This program get contents of the files and
*   save it in a variable
*/

#include <bits/stdc++.h>

using namespace std;

void obtainContentText( string nametoFile, string *contentText ){

    ifstream filetoOpen;
    string content, message;

    filetoOpen.open( nametoFile.c_str(), ios::binary );

    if( filetoOpen.fail() ){
        cout<< "Error opening file";
        exit(EXIT_FAILURE);
    }

    while( !filetoOpen.eof() ){
        getline( filetoOpen, content );
        *contentText = *contentText + content;
    }

}