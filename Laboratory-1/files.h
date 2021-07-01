/*  @brief files.h
*   Get file content
*/

#ifndef FILES_H
#define FILES_H

#include <bits/stdc++.h>

using namespace std;

void obtainContent( string nameFile, string *vartoSave, string *nameWithoutExtension );
void writeKeytoFile( string typeCipher, string *key );
void saveFile( string texttoSave, string typeCipher, string operationtoDo );

#endif 