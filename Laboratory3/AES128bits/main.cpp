/*  @brief main.cpp
*   Este programa contiene las llamadas
*   a las funciones encargadas de obtener las
*   10 subllaves para AES de 128 bits
*/

#include <bits/stdc++.h>
#include "KeySchedule.h"

using namespace std;

int main(){
    string nameFile;

    system( "cls" );

    cout<< "\t \t Key Schedule for AES (128 bits) " << endl;
    cout<< " Key file name: ";
    cin>> nameFile;

    KeyScheduleAES( nameFile );

}