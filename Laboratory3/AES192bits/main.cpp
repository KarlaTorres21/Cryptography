/*  @brief main.cpp
*   Este programa contiene las llamadas
*   a las funciones encargadas de obtener las
*   12 subllaves para AES de 192 bits
*/

#include <bits/stdc++.h>
#include "KeySchedule.h"

using namespace std;

int main(){
    string nameFile;

    system( "cls" );

    cout<< "\t \t Key Schedule for AES (192 bits) " << endl;
    cout<< " Key file name: ";
    cin>> nameFile;

    KeyScheduleAES( nameFile );

}