/*  @brief main.cpp
*   Este programa contiene las llamadas
*   a las funciones encargadas de realizar
*   la tabla de GF(2^n)
*/

#include <bits/stdc++.h>
#include "GF2.h"

using namespace std;

int main(){
    int n;
    string response;

    system( "cls" );

    cout<< "\t \t Finite Fields" << endl;
    cout<< " Enter the value of n (3 - 8): ";
    cin>> n;
    cout<< " Do you want to save in polynomial mode? ";
    cin>> response;

    calculateGF2( n, response );

}
