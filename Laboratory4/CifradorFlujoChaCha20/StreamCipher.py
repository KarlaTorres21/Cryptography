from base64 import b64encode
from base64 import b64decode
from Crypto.Cipher import ChaCha20
from Crypto.Random import get_random_bytes

location = "./Archivos/"
IVSize = 12

def encryptChaCha20( message ):
    key = get_random_bytes( 32 )
    if( IVSize == 8 ):
        cipher = ChaCha20.new( key = key )
    else:
        IV = get_random_bytes( IVSize )
        cipher = ChaCha20.new( key = key, nonce = IV )
    cipherText = cipher.encrypt( message )
    return cipher.nonce, key, cipherText

def decryptChaCha20( IV, key, cipherText ):
    cipher = ChaCha20.new( key = key, nonce = IV )
    plainText = cipher.decrypt( cipherText )
    return plainText

def readFile( name ):
    file = open( name, "r" )
    content = file.read()
    file.close()
    return content

def saveEncrypt( IV, key, cipherText ):
    file = open( location + "IVandKey.txt", "w" )
    file.write( IV.hex() + key.hex() )
    file.close()

    file = open( location + "MessageEncrypt.txt", "w" )
    file.write( b64encode( cipherText ).decode('utf-8') )
    file.close()

def obtainContent( ):
    file = open( location + "IVandKey.txt", "r" )
    IVandKey = file.read()
    file.close()

    file = open( location + "MessageEncrypt.txt", "r" )
    content = file.read()
    file.close()
    return IVandKey, content

print(" Do you want encrypt or decrypt (0/1)? ")
if( input() == '0' ):
    print(" \t ChaCha20 Encrypt ")
    print(" Name File: ")
    message = readFile( location + input() )
    IV, key, cipherText = encryptChaCha20( message.encode() )
    saveEncrypt( IV, key, cipherText )

else:
    print(" \t ChaCha20 Decrypt ")
    IVandKey, cipherText = obtainContent()
    IV = bytes.fromhex( IVandKey[ 0 : IVSize*2 ] )
    key = bytes.fromhex( IVandKey[ IVSize*2 : ] )
    plainText = decryptChaCha20( IV, key, b64decode(cipherText) )
    
    file = open( location + "MessageDecrypt.txt", "w" )
    file.write( plainText.decode() )
    file.close()
