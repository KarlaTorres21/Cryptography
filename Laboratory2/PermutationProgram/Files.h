/*  @brief Files.h
*   Get file content
*/

#ifndef FILES_H
#define FILES_H

#include <bits/stdc++.h>

using namespace std;

void obtainTable( string nameFile, string *valueofPhi );
void writetoFile( string nameofFile );
void writePermutation( string nameofFile, vector<int> *values );
void obtainText( string nameFile, string *fileContent );
void writeMessage( string *contenttoWrite, string nametoSave );

#endif 