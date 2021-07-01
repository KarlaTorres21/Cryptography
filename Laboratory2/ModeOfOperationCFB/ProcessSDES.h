/*  @brief ProcessSDES.h
*  Archivo que contiene los prototipos de las funciones que
*  ayudaran a realizar el cifrado y descifrado usando SDES
*/

#ifndef PROCESSSDES_H
#define PROCESSSDES_H

#include <bits/stdc++.h>

using namespace std;

void applyPermutationIP( char *messagetoEncrypt );
void roundOne( char *messagePermutation, bitset<8> subKey1, bitset<8> subKey2, string actiontoDo );
void expasionPermutationByte( bitset<8> *expansionPermutation, bitset<4> partRight );
void xorOperationAndFindTable( bitset<8> *operatorOne, bitset<8> operatorTwoKey1, bitset<2> *resultTable, int type );
void P4andXor( bitset<4> *S0andS1, bitset<4> partLeft, bitset<4> partRight, bitset<8> *resultRound1 );
void roundTwo( bitset<8> resultRound1, bitset<8> subKey2, bitset<8> subKey1, long int *potencia, string actiontoDo );
void permutationInverse( bitset<8> resultRound2, long int *potencia );

#endif
