from base64 import b64encode
from base64 import b64decode
from Crypto.Cipher import Blowfish
from Crypto.Random import get_random_bytes

location = "./Archivos/Blowfish/"
sizeKey = 50

def encryptBlowfish( plainText ):
    key = get_random_bytes( sizeKey )
    cipher = Blowfish.new( key, Blowfish.MODE_OFB )
    cipherText = cipher.encrypt( plainText )
    return key, cipher.iv, cipherText

def decryptBlowfish( key, IV, cipherText ):
    cipher = Blowfish.new( key, Blowfish.MODE_OFB, iv = IV )
    plainText = cipher.decrypt( cipherText )
    return plainText

def readFile( name ):
    file = open( name, "r" )
    content = file.read()
    file.close()
    return content

def saveEncrypt( key, IV, cipherText ):
    file = open( location + "KeyIV.txt", "w" )
    file.write( key.hex() + IV.hex() )
    file.close()

    file = open( location + "MessageEncrypt.txt", "w" )
    file.write( b64encode( cipherText ).decode('utf-8') )
    file.close()

def obtainContent( ):
    file = open( location + "KeyIV.txt", "r" )
    keyandIV = file.read()
    file.close()

    file = open( location + "MessageEncrypt.txt", "r" )
    content = file.read()
    file.close()
    return keyandIV, content

print(" Do you want encrypt or decrypt (0/1)? ")
if( input() == '0' ):
    print(" Name File: ")
    message = readFile( location + input() )
    key, IV, cipherText = encryptBlowfish( message.encode() )
    saveEncrypt( key, IV, cipherText )

else:
    keyandIV, cipherText = obtainContent()
    key = bytes.fromhex( keyandIV[0:(sizeKey*2)] )
    IV = bytes.fromhex( keyandIV[sizeKey*2:] )
    plainText = decryptBlowfish( key, IV, b64decode(cipherText) )
    file = open( location + "MessageDecrypt.txt", "w" )
    file.write( plainText.decode() )
    file.close()