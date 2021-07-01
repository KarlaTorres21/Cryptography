from base64 import b64encode
from base64 import b64decode
from Crypto.Cipher import DES3
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad, unpad

location = "./Archivos/3DES/"
blockSize = 8
keySize = 16

def modeCBC( IV, key, actionToDo ):
    if( actionToDo == "Encrypt" ):
        cipher = DES3.new( key, DES3.MODE_CBC )
    else:
        cipher = DES3.new( key, DES3.MODE_CBC, iv = IV )
    return cipher.iv, cipher

def encryptMessage( cipher, plainText ):
    cipherText = cipher.encrypt( plainText )
    return cipherText

def decryptMessage( cipher, cipherText ):
    plainText = cipher.decrypt( cipherText )
    return plainText

def generationKey():
    while True:
        try:
            key = DES3.adjust_key_parity( get_random_bytes( 16 ) )
            break
        except ValueError:
            pass 
    return key

def padding( plainText ):
    return pad( plainText, blockSize )

def removePadding( cipherText ):
    return unpad( cipherText, blockSize )

def readFile( name ):
    file = open( name, "r" )
    content = file.read()
    file.close()
    return content

def saveEncrypt( IV, key, cipherText, modeOperation ):
    file = open( location + "IVandKey" + modeOperation + ".txt", "w" )
    file.write( key.hex() + IV.hex() )
    file.close()

    file = open( location + "MessageEncrypt" + modeOperation + ".txt", "w" )
    file.write( b64encode( cipherText ).decode('utf-8') )
    file.close()

def obtainContent( modeOperation ):
    file = open( location + "IVandKey" + modeOperation + ".txt", "r" )
    key = file.read()
    file.close()

    file = open( location + "MessageEncrypt" + modeOperation + ".txt", "r" )
    content = file.read()
    file.close()
    return key, content

print(" Do you want encrypt or decrypt (0/1)? ")
if( input() == '0' ):
    print(" Name File: ")
    message = readFile( location + input() )
    key = generationKey()
    # MODO CBC
    IV, cipher = modeCBC( 0, key, "Encrypt" )
    message = padding( message.encode() )
    cipherText = encryptMessage( cipher, message ) 
    saveEncrypt( IV, key, cipherText, "CBC" )

else:
    KeyandIV, cipherText = obtainContent( "CBC" )
    key = bytes.fromhex( KeyandIV[0 : keySize*2] )
    IV = bytes.fromhex( KeyandIV[keySize*2 : ] )
    IV, cipher = modeCBC( IV, key, "Decrypt" )
    plainText = decryptMessage( cipher, b64decode(cipherText) )
    plainText = removePadding( plainText )
    file = open( location + "MessageDecryptCBC.txt", "w" )
    file.write( plainText.decode() )
    file.close()
