/*  @brief SDES.h
*  Archivo que contiene los prototipos de las funciones de 
*  cifrado y descifrado haciendo uso unicamente de DES 
*  Simplificado
*/

#ifndef SDES_H
#define SDES_H

#include <bits/stdc++.h>

using namespace std;

void KeysGenerateSDES( bitset<10> *binaryKey, bitset<8> *subKey1, bitset<8> *subKey2, int ifGenerateorNot );
void EncryptSDES( char *messagetoEncrypt, bitset<8> subKey1, bitset<8> subKey2 );
void DecryptSDES( char *messagetoEncrypt, bitset<8> subKey1, bitset<8> subKey2 );

#endif
