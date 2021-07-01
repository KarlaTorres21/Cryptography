/*  @brief KeyScheduleProcess.h
*   Libreria que contiene los prototipos de las
*   funciones intermedias para calcular las
*   subclaves
*/

#ifndef KEYSCHEDULEPROCESS_H
#define KEYSCHEDULEPROCESS_H

#include <bits/stdc++.h>

using namespace std;

void getKey( string nameFile, string *keyString );
void keyBit( string keyString, bitset<8> W[4][6] );
void RotBytes( bitset<8> W[4][6], bitset<8> T[4][1] );
void SubBytes( bitset<8> T[4][1] );
void XorRC( bitset<8> T[4][1], int i );
void modifyValues( bitset<8> T[4][1], bitset<8> W[4][6] );
void imprimirMatriz( bitset<8> W[4][6], int i, bitset<8> leftOver[4][2] );
void saveValues( bitset<8> W[4][6], bitset<8> leftOver[4][2] );

#endif
