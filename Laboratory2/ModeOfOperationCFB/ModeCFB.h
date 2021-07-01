/*  @brief ModeCFB.h
*  Archivo que contiene los prototipos de las funciones 
*  encargadas de llevar a cabo el modo de operacion
*/

#ifndef MODECFB_H
#define MODECFB_H

#include <bits/stdc++.h>

using namespace std;

void modeOfOperationCFBCipher( string *contentText, string nameFile );
void modeOfOperationCFBDecrypt( string *contentText, string nameFile );

#endif