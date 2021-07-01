/*  @brief Process.cpp
*   Este programa obtiene todas las variables
*   que son necesarias, asi como sus transformaciones
*/

#include <bits/stdc++.h>

using namespace std;

extern map<int, int> tablePermutation;

void inversePermutation( string *valueofPhi ){
    string previous = ""; 
    register int auxCont = 1;

    for( register int i = 0; i < (*valueofPhi).size(); i++ ){
        previous = previous + (*valueofPhi)[i];
        if( (*valueofPhi)[i] == ' ' ){
            tablePermutation.insert( pair<int, int>( stoi( previous, nullptr, 10 ), auxCont ) );
            auxCont++;
            previous = "";
        }
    }
}

vector<int> randomPermutation( int n ){

    vector<int> randomNumbers;
    
    for( register int i = 0; i < n; i++ )
        randomNumbers.push_back( i+1 ); 

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    shuffle ( randomNumbers.begin(), randomNumbers.end(), default_random_engine( seed ) );

    return randomNumbers;
        
}

void mappingValues( string *valueofPhi ){

    string previous = ""; 
    register int j = 0, auxCont = 1;

    // Usamos una String auxiliar en caso de que el numero tenga dos digitos
    for( register int i = 0; i < (*valueofPhi).size(); i++ ){
        previous = previous + (*valueofPhi)[i];
        if( (*valueofPhi)[i] == ' ' ){
            tablePermutation.insert( pair<int, int>( auxCont, stoi( previous, nullptr, 10 ) ) );
            auxCont++;
            previous = "";
        }
    }
}

void verifytoMod( string *messagetoVerify ){

    int mod = (*messagetoVerify).size() % tablePermutation.size();
    int missing = tablePermutation.size() - mod;
    char specialCharacters[ missing ];

    if( mod != 0 ){
        cout<< " Special characters added: " << missing << endl;
        for( register int i = 0; i < missing; i++ )
            specialCharacters[i] = char( 40+i ); 
        specialCharacters[ missing ] = '\0';
        *messagetoVerify = *messagetoVerify + specialCharacters;
    }
}

void reviewMod( string *messagetoVerify ){

    int tamBloque = tablePermutation.size() / 8;
    int mod = (*messagetoVerify).size() % tamBloque;
    int missing = tamBloque - mod;
    char specialCharacters[ missing ];

    if( mod != 0 ){
        cout<< " Special characters added: " << missing << endl;
        for( register int i = 0; i < missing; i++ )
            specialCharacters[i] = char( 40+i ); 
        specialCharacters[ missing ] = '\0';
        *messagetoVerify = *messagetoVerify + specialCharacters;
    }
}

string askforType( void ){

    string answer;

    cout<< " Do you want encrypt/decrypt at the bit level? ";
    cin>> answer;

    return answer;

}

