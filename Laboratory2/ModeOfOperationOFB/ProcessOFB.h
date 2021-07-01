/*  @brief ProcessCFB.h
*  Archivo que contiene los prototipos de las funciones 
*  encargadas de llevar a cabo el procedimiento del
*  modo de operacion CFB
*/

#ifndef PROCESSCFB_H
#define PROCESSCFB_H

#include <bits/stdc++.h>

using namespace std;

void vectorIVGeneration( string *vectorIV );
void saveVectorIV( string vectorIV );
void getIV( string *IV, string nameFile );

#endif