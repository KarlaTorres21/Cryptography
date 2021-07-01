from math import ceil, sqrt
from timeit import default_timer
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

def obtainPower( numbers ):
    for power in numbers:
        print( pow( power, numbers[power] ), " ", end = "" )


startTime = default_timer()
numbers = findPrimeFactors( int(sys.argv[1]) )
print( " Prime factors {number : power}  = ", numbers )
print( " Factors number^(power): ", end = "" )
obtainPower( numbers )
endTime = default_timer()
print()
print( " Execution time: ", endTime - startTime, "segundos" )
