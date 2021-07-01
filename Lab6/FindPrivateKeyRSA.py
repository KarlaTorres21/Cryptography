from math import ceil, sqrt
from timeit import default_timer
from Crypto.Util.number import inverse
import sys

def findPrimeFactors( number ):
    rango = ceil( sqrt( number ) )
    numbers = {}
    count = 0

    while number % 2 == 0  :
        number = number / 2
        count += 1
        numbers.update({ 2: count })

    for i in range( 3, rango + 1, 2 ) :
        count = 0
        while number % i == 0  :
            number = number / i
            count += 1
            numbers.update({ i: count })

    if number != 1:
        numbers.update({ int(number): 1 })

    return numbers

def obtainPhiN( numbers ):
    phiN = 1
    for factor in numbers:
        phiN = phiN * ( factor - 1 )
    return phiN

startTime = default_timer()
numbers = findPrimeFactors( int(sys.argv[2]) )
print( " Prime factors {number : power}  = ", numbers )
phiN = obtainPhiN( numbers )
print( " Value of Phi(n)  = ", phiN )
print( " Private Key d is: ", inverse( int(sys.argv[1]), phiN ) )
endTime = default_timer()

print( " Execution time: ", endTime - startTime, "segundos" )
