/*  @brief KeyGeneration.h
*   Programa que realiza la tarea de generar la
*   llave, asi como subllaves
*/

#ifndef KEYGENERATION_H
#define KEYGENERATION_H

#include <bits/stdc++.h>

using namespace std;

void generateKey( string *key );
void saveKeytoFile( string key );

void applyPermutation10( bitset<10> *binaryKey );
void applyShiftSubKeys( bitset<10> *binaryKey, int numberShift );
void applyPermutation8( bitset<10> *binaryKey, bitset<8> *subKey );
void obtainContentKey( string nameFile, string *key );

#endif 