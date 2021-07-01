from base64 import b64encode
from base64 import b64decode
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes

location = "./Archivos/AES/"
KeySizeByte = 32

def encryptAES( plainText ):
    key = get_random_bytes( KeySizeByte )
    cipher = AES.new( key, AES.MODE_EAX )
    cipherText, tag = cipher.encrypt_and_digest( plainText )
    return cipher.nonce, key, tag, cipherText

def decryptAES( IV, key, tag, cipherText ):
    cipher = AES.new(key, AES.MODE_EAX, nonce = IV)
    plainText = cipher.decrypt( cipherText )
    try:
        cipher.verify(tag)
        print("The message is authentic")
    except ValueError:
        print("Key incorrect or message corrupted")
    return plainText

def readFile( name ):
    file = open( name, "r" )
    content = file.read()
    file.close()
    return content

def saveEncrypt( IV, key, tag, cipherText ):
    file = open( location + "KeyIVTag.txt", "w" )
    file.write( key.hex() + IV.hex() + tag.hex() )
    file.close()

    file = open( location + "MessageEncrypt.txt", "w" )
    file.write( b64encode( cipherText ).decode('utf-8') )
    file.close()

def obtainContent( ):
    file = open( location + "KeyIVTag.txt", "r" )
    KeyIVTag = file.read()
    file.close()

    file = open( location + "MessageEncrypt.txt", "r" )
    content = file.read()
    file.close()
    return KeyIVTag, content

print(" Do you want encrypt or decrypt (0/1)? ")
if( input() == '0' ):
    print(" Name File: ")
    message = readFile( location + input() )
    IV, key, tag, cipherText = encryptAES( message.encode() )
    saveEncrypt( IV, key, tag, cipherText )

else:
    KeyIVTag, cipherText = obtainContent()
    key = bytes.fromhex( KeyIVTag[0 : KeySizeByte*2] )
    IV = bytes.fromhex( KeyIVTag[KeySizeByte*2 : ( KeySizeByte*2 ) + 32] )
    tag = bytes.fromhex( KeyIVTag[( KeySizeByte*2 ) + 32:] )
    plainText = decryptAES( IV, key, tag, b64decode(cipherText) )
    file = open( location + "MessageDecrypt.txt", "w" )
    file.write( plainText.decode() )
    file.close()
