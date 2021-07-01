/*  @brief Process.cpp
*   
*/

#include <bits/stdc++.h>
#include "ProcessSDES.h"

using namespace std;

const int S0[4][4] = { { 1, 0, 3, 2 },
                        { 3, 2, 1, 0 },
                        { 0, 2, 1, 3 },
                        { 3, 1, 3, 2 } };
const int S1[4][4] = { { 0, 1, 2, 3 },
                        { 2, 0, 1, 3 },
                        { 3, 0, 1, 0 },
                        { 2, 1, 0, 3 } };

void applyPermutationIP( char *messagetoEncrypt ){
    long int position;
    int tablePermutation[8] = {3, 1, 7, 2, 4, 6, 8, 5}, onOrOff;
    char characterAux = *messagetoEncrypt;

    for( register int i = 0; i < 8; i++ ){
        position = tablePermutation[i] - 1;
        onOrOff = ( characterAux & ( 1 << i ));

        if( onOrOff == 0 )
            (*messagetoEncrypt) &=  ~( 1 << position  );

        else 
            (*messagetoEncrypt) |= ( 1 << position );
    }
}

void roundOne( char *messagePermutation, bitset<8> subKey1, bitset<8> subKey2, string actiontoDo ){

    long int potencia = 0;
    bitset<8> expansionPermutation, resultRound1;
    bitset<4> partLeft, partRight, S0andS1;
    bitset<2> tableLeft, tableRight;

    partRight = (*messagePermutation) & 15;
    partLeft = (*messagePermutation) >> 4;

    expasionPermutationByte( &expansionPermutation, partRight );

    if( actiontoDo.compare("Decrypt") ){
        xorOperationAndFindTable( &expansionPermutation, subKey1, &tableLeft, 1 );
        xorOperationAndFindTable( &expansionPermutation, subKey1, &tableRight, 2 );
    }
    else{
        xorOperationAndFindTable( &expansionPermutation, subKey2, &tableLeft, 1 );
        xorOperationAndFindTable( &expansionPermutation, subKey2, &tableRight, 2 );
    }

    S0andS1 = bitset<4>( tableLeft.to_string() + tableRight.to_string() );
    P4andXor( &S0andS1, partLeft, partRight, &resultRound1 );
    roundTwo( resultRound1, subKey2, subKey1, &potencia, actiontoDo );
    (*messagePermutation) = static_cast<char>(potencia);
}

void expasionPermutationByte( bitset<8> *expansionPermutation, bitset<4> partRight ){

    int onOrOff, tablePermutation[8] = { 2, 8, 3, 5, 4, 6, 1, 7 }, aux = 0;

    for( register int i = 0; i < 8; i+=2 ){ 
        (*expansionPermutation)[ tablePermutation[i] -1 ] = partRight[ aux ];
        (*expansionPermutation)[ tablePermutation[i+1] -1 ] = partRight[ aux ];
        aux++;
    }

}

void xorOperationAndFindTable( bitset<8> *operatorOne, bitset<8> operatorTwoKey, bitset<2> *resultTable, int type ){

    bitset<2> column, row;
    bitset<16> resultBinaryTable;
    int numCol, numRow, result;

    if( type == 1 ){
        (*operatorOne) ^= operatorTwoKey;
        for( register int i = 0; i < 2; i++ )
            column[i] = (*operatorOne)[i + 5];

        row[0] = (*operatorOne)[4];     row[1] = (*operatorOne)[7];  
    }
    else{
        for( register int i = 0; i < 2; i++ )
            column[i] = (*operatorOne)[i + 1];

        row[0] = (*operatorOne)[0];     row[1] = (*operatorOne)[3];
    }

    numCol = (int)(column.to_ulong());
    numRow = (int)(row.to_ulong());

    if( type == 1 )
        result = S0[numRow][numCol]; 
    else
        result = S1[numRow][numCol];

    resultBinaryTable = bitset<16>(result);
    (*resultTable)[0] = resultBinaryTable[0];
    (*resultTable)[1] = resultBinaryTable[1];

}

void P4andXor( bitset<4> *S0andS1, bitset<4> partLeft, bitset<4> partRight, bitset<8> *resultRound1 ){

    int P4[] = {4, 2, 1, 3};
    bitset<4> resultP4;

    for( register int i = 0; i < 4; i++ )
        resultP4[i] = (*S0andS1)[ P4[i] - 1 ];

    resultP4 ^= partLeft;

    (*resultRound1) = bitset<8>( resultP4.to_string() + partRight.to_string() );

}

void roundTwo( bitset<8> resultRound1, bitset<8> subKey2, bitset<8> subKey1, long int *potencia, string actiontoDo ){

    bitset<4> partLeft, partRight, S0andS1;
    bitset<8> expansionPermutationRound2, resultRound2;
    bitset<2> tableLeft, tableRight;
    
    for( register int i = 0; i < 4; i++ ){
        partRight[i] = resultRound1[i+4];
        partLeft[i] = resultRound1[i];
    }

    expasionPermutationByte( &expansionPermutationRound2, partRight );
    if( actiontoDo.compare("Decrypt") ){
        xorOperationAndFindTable( &expansionPermutationRound2, subKey2, &tableLeft, 1 );
        xorOperationAndFindTable( &expansionPermutationRound2, subKey2, &tableRight, 2 );
    }
    else{
        xorOperationAndFindTable( &expansionPermutationRound2, subKey1, &tableLeft, 1 );
        xorOperationAndFindTable( &expansionPermutationRound2, subKey1, &tableRight, 2 );
    }
    S0andS1 = bitset<4>( tableLeft.to_string() + tableRight.to_string() );
    P4andXor( &S0andS1, partLeft, partRight, &resultRound2 );
    permutationInverse( resultRound2, potencia );
}

void permutationInverse( bitset<8> resultRound2, long int *potencia ){

    int permutationTable[] = {3, 1, 7, 2, 4, 6, 8, 5};
    bitset<8> resultInverse;

    for( register int i = 0; i < 8; i++  )
        if( ( resultRound2[ permutationTable[i] - 1 ] ) == 1 )
            *potencia += ( 1 << i );
}
