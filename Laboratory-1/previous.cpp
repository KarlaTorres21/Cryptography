#include <bits/stdc++.h>

using namespace std;

// Variables globales
string alphabet, message, key, nameMessage;
map<char, int> tableAlphabet;

// Prototipo de funciones
int mainMenu( void );
void askforKeyandFilesName( string typeCipher, string actiontoDo );
void obtainContent( string nameFile, string typeFile );
void mapeoAlphabet( void );
void generateKeyVigenere( void );
void writeKeytoFile( string typeCipher );
void encryptVigenere( void ); 
void saveFile( string texttoSave, string typeCipher, string operationtoDo );
void decryptVigenere( void );
void negativeNumbMod( int *modifyModule, int sizeAlphabet );
void askforKeyAffine( void );
int verifyAffineKey( int sizeAlphabet, int a );
void generateKeyAffine( void );
void encryptAffine( void );
void askforNumberInverse( void );
void extendedEuclid( int valueofA, int valueofN, int *s, int *t, int *gcdResult );
void decryptAffine( void );

int main(){

    int option = mainMenu();
    system("cls");
    map<char, int>::iterator itr; 

    switch (option){
    case 1:
        cout<< "\t \t Encrypt Vigenere Cipher" << endl;
        askforKeyandFilesName( "Vigenere", "Encrypt" );
        encryptVigenere( );
        break;
    case 2:
        cout<< "\t \t Decrypt Vigenere Cipher" << endl;
        askforKeyandFilesName( "Vigenere", "Decrypt" );
        decryptVigenere( );
        break;
    case 3:
        cout<< "\t \t Verify if a candidate key for affine cipher is valid key" << endl;
        askforKeyAffine( );
        break;
    case 4:
        cout<< "\t \t Calculate inverse a mod n " << endl;
        askforNumberInverse( );
        break;
    case 5:
        cout<< "\t \t Encrypt Affine Cipher" << endl;
        askforKeyandFilesName( "Affine", "Encrypt" );
        cout << "\nThe map gquiz1 is : \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    for (itr = tableAlphabet.begin(); itr != tableAlphabet.end(); ++itr) { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
        encryptAffine( );
        break;
    case 6: 
        cout<< "\t \t Decrypt Affine Cipher" << endl;
        askforKeyandFilesName( "Affine", "Decrypt" );
        decryptAffine( );
        break;
    default:
        cout<< "Invalid option";
        break;
    }
}

void decryptAffine( void ){

    int s, inverseNumber, gcdResult, numCharacter;
    char decryptMessage[ message.size() ];

    extendedEuclid( tableAlphabet.find( key[0] )->second, alphabet.size(), &s, &inverseNumber, &gcdResult );

    for( register int i = 0; i < message.size(); i++ ){
        numCharacter = inverseNumber * ( tableAlphabet.find( message[i] )->second + alphabet.size() - tableAlphabet.find( key[1] )->second );
        numCharacter = numCharacter % alphabet.size();
        decryptMessage[i] = alphabet[numCharacter];
    }

    decryptMessage[ message.size() ] = '\0';

    cout<< decryptMessage;

    saveFile( decryptMessage, ".aff", "Decrypt" );

}

void extendedEuclid( int valueofA, int valueofN, int *s, int *t, int *gcdResult ){

    int s0 = 1, s1 = 0, t0 = 0, t1 = 1, residue, quotient, sizeAlphabet = valueofN;

    if( valueofA == 0 ){
        *gcdResult = 0;
        *s = 1;
        *t = 0; 
        return;
    } 

    while( valueofA != 0 ){

        residue = valueofN % valueofA;
        quotient = ( valueofN - residue ) / valueofA;
        *s = s0 - ( quotient * s1 );
        *t = t0 - ( quotient * t1 );
        valueofN = valueofA;
        valueofA = residue;
        s0 = s1;
        s1 = *s;
        t0 = t1;
        t1 = *t;

    }

    if( s0 < 0 )
        negativeNumbMod( &s0, sizeAlphabet );

    if( t0 < 0 )
        negativeNumbMod( &t0, sizeAlphabet );

    *gcdResult = valueofN;
    *s = s0;
    *t = t0;
    return;

}

void askforNumberInverse( void ){

    int valueofA, valueofB, valueofN, response, s, t, gcdResult;

    cout<< " Enter the value of a: ";
    cin>> valueofA;

    cout<< " Enter the value of b: ";
    cin>> valueofB;

    cout<< " Enter the value of n: ";
    cin>> valueofN;

    extendedEuclid( valueofA, valueofN, &s, &t, &gcdResult );

    cout<< " The inverse of " << valueofA << " mod " << valueofN << " is: " << t;
    
}

void encryptAffine( void ){

    char messageCipher[ message.size() ];
    int valueAandMi, finalValue;

    for( register int i = 0; i < message.size(); i++ ){
        valueAandMi = tableAlphabet.find( key[0] )->second * tableAlphabet.find( message[i] )->second;
        finalValue = ( valueAandMi + tableAlphabet.find( key[1] )->second ) % alphabet.size();
        messageCipher[i] = alphabet[ finalValue ];
    }

    messageCipher[ message.size() ] = '\0';

    cout<< messageCipher;

    saveFile( messageCipher, ".aff", "Encrypt" );

}

void generateKeyAffine( void ){

    srand( getpid() );
    int a = 2 + rand() % ( alphabet.size() - 1 ), b = 2 + rand() % ( alphabet.size() - 1 );
    int correctKey = verifyAffineKey( alphabet.size(), a );
    char keyPrevious[2];

    while( correctKey == 0 ){
        a = 2 + rand() % ( alphabet.size() - 1 );
        correctKey = verifyAffineKey( alphabet.size(), a );
    }
    keyPrevious[0] = alphabet[a]; keyPrevious[1] = alphabet[b]; keyPrevious[2] = '\0';

    cout<< "gcd( " << a << ", " << alphabet.size() << " ) -> Ek = ( "<< a << ", " << b << " )";

    key = keyPrevious;
    writeKeytoFile( "Affine" );

}

int verifyAffineKey( int sizeAlphabet, int a ){
    if( __gcd( a, sizeAlphabet ) == 1 )
        return 1;
    else
        return 0;
}

void askforKeyAffine( void ){

    ifstream filetoOpen;
    string responseKey;
    int sizeAlphabet, a, b;

    cout<< " Do you know the size of the alphabet? ";
    cin>> responseKey;

    if( !responseKey.compare("Yes") ){
        cout<< " Alphabet size: ";
        cin>> sizeAlphabet;
    }

    else{
        cout<< " Alphabet File Name: ";
        cin>> responseKey;
        filetoOpen.open( responseKey.c_str(), ios::in );

        while( !filetoOpen.eof() )
            getline(filetoOpen, alphabet);

        filetoOpen.close();
    
        sizeAlphabet = alphabet.size();
        cout<< " Alphabet size is: " <<sizeAlphabet <<endl;
    }

    cout<< " Enter a and b: ";
    cin>> a; 
    cin>> b;

    if( verifyAffineKey( sizeAlphabet, a ) )
        cout<< " Candidate key is a valid key";
    else 
        cout<< " Candidate key is an invalid key";

}

void negativeNumbMod( int *modifyModule, int sizeAlphabet ){
    *modifyModule = sizeAlphabet - ( (-*modifyModule) % sizeAlphabet );
}

void decryptVigenere( void ){

    int numCharacter, modMessageandKey;
    char decryptMessage[ message.size() ];

    for( register int i = 0; i < message.size(); i++ ){
        numCharacter = ( tableAlphabet.find( message[i] )->second - tableAlphabet.find( key[i%key.size()] )->second );
        if( numCharacter < 0 )
            negativeNumbMod( &numCharacter, alphabet.size() );
        else 
            numCharacter = numCharacter % alphabet.size();
        decryptMessage[i] = alphabet[numCharacter];
    }

    decryptMessage[ message.size() + 1 ] = '\0';

    cout<< decryptMessage;

    saveFile( decryptMessage, ".vig", "Decrypt" );

}

void saveFile( string texttoSave, string typeCipher, string operationtoDo ){

    ofstream fileEncrypt;
    string nametoSave = nameMessage + typeCipher;

    if( !(operationtoDo.compare("Decrypt")) )
        nametoSave = operationtoDo + nameMessage + typeCipher;

    fileEncrypt.open( nametoSave.c_str() , ios :: out );

    if( fileEncrypt.fail() ){
        cout<< "Error writing the generated key";
        exit( EXIT_FAILURE );
    }

    fileEncrypt<< texttoSave;
    fileEncrypt.close();

}


void encryptVigenere( void ){

    int numCharacter, modMessageandKey;
    char messageCipher[ message.size() ];

    for( register int i = 0; i < message.size(); i++ ){
         numCharacter = ( tableAlphabet.find( message[i] )->second + tableAlphabet.find( key[i%key.size()] )->second ) % alphabet.size();
         messageCipher[i] = alphabet[numCharacter];
    }

    messageCipher[ message.size() + 1 ] = '\0';

    cout<< messageCipher;

    saveFile( messageCipher, ".vig", "Encrypt" );

}

void writeKeytoFile( string typeCipher ){

    ofstream fileGenerate;
    string nameFile = "KeyGenerate" + typeCipher + ".txt";
    fileGenerate.open( nameFile.c_str(), ios :: out );

    if( fileGenerate.fail() ){
        cout<< "Error writing the generated key";
        exit( EXIT_FAILURE );
    }

    fileGenerate<< key;
    fileGenerate.close();

}

void generateKeyVigenere( void ){

    //limite_inferior + rand() % (limite_superior +1 - limite_inferior)
    int sizeKey = 5 + rand() % ( 15 + 1 - 5 ), contKey;
    char keyPrevious[ sizeKey ];
    srand( getpid() );

    cout<< "sizeKey: " << sizeKey << endl;
    cout<< "Numeros llave: ";

    for( register int i = 0; i < sizeKey; i++ ){
            contKey = rand() % alphabet.size();
            cout<< contKey << " ";
            keyPrevious[i] = alphabet[contKey];
    }

    keyPrevious[sizeKey] = '\0';

    key = keyPrevious;

    writeKeytoFile( "Vigenere" );

}

void mapeoAlphabet( void ){

    for( register int i = 0; i < alphabet.size() ; i++ )
        tableAlphabet.insert( pair<char, int>( alphabet[i], i ));

}

void obtainContent( string nameFile, string typeFile ){

    ifstream filetoOpen;
    string nameWithoutExtension;
    int txtPosicion;

    filetoOpen.open( nameFile.c_str(), ios::in );

    if( filetoOpen.fail() ){
        cout<< "Error opening file";
        exit(EXIT_FAILURE);
    }

    if( typeFile.compare("alphabet") == 0 ){
        while( !filetoOpen.eof() )
            getline(filetoOpen, alphabet);
    }

    else if( typeFile.compare("message") == 0 ){
        txtPosicion = nameFile.find( ".txt" ) + 4;
        nameMessage = nameFile.substr(0, txtPosicion);
        while( !filetoOpen.eof() )
            getline(filetoOpen, message);
    }

    else{
        while( !filetoOpen.eof() )
            getline(filetoOpen, key);
    }

    filetoOpen.close();

}

void askforKeyandFilesName( string typeChiper, string actiontoDo ){

    string responseKey, nameAlphabet, nameKey;

    if( actiontoDo.compare("Encrypt") == 0 ){
        cout<< " Do you want a randomly key? ";
        cin>> responseKey;
    }

    cout<< " Alphabet File Name: ";
    cin>> nameAlphabet;
    obtainContent( nameAlphabet, "alphabet" );
    mapeoAlphabet( );
    cout<< alphabet << endl;

    cout<< " Input File Name: ";
    cin>> nameMessage;
    obtainContent( nameMessage, "message" );
    cout<< message << endl;

    if( responseKey.compare("Yes") || actiontoDo.compare("Decrypt") == 0 ){
        cout<< " Key File Name: ";
        cin>> nameKey;
        obtainContent( nameKey, "key" );
        cout<< key << endl;
    }
    else{
        if( !( typeChiper.compare("Vigenere") ) )
            generateKeyVigenere( );
        else 
            generateKeyAffine( );
    }

}

int mainMenu( void ){

    int option;

    cout<< "\t What do you want to do? " << endl;
    cout<< " 1. Encrypt Vigenere Cipher" << endl;
    cout<< " 2. Decrypt Vigenere Cipher" << endl;
    cout<< " 3. Verify if a candidate key for affine cipher is valid key" << endl;
    cout<< " 4. Calculate inverse a mod n" << endl;
    cout<< " 5. Encrypt Affine Cipher" << endl;
    cout<< " 6. Decrypt Affine Cipher" << endl;
    cout<< " Select an option: ";
    cin>> option;

    return option;

}
