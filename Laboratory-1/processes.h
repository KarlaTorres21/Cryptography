/*  @brief processes.h
*   Intermediate tasks
*/

#ifndef PROCESSES_H
#define PROCESSES_H

#include <bits/stdc++.h>

using namespace std;

void mapeoAlphabet( string *alphabet );
void negativeNumbMod( int *modifyModule, int sizeAlphabet );
int verifyAffineKey( int sizeAlphabet, int a );
void generateKeyVigenere( string *key, string *message, string *alphabet );
void generateKeyAffine( string *key, string *alphabet );
void extendedEuclid( int valueofA, int valueofN, int *s, int *t, int *gcdResult );

#endif