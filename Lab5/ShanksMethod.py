from math import ceil, sqrt
from timeit import default_timer
import sys

def babyStepGiantStepAlgorithm( g, p, h):
    m = ceil( sqrt(p) ) + 1
    giantStep = [0] * m

    for i in range( 1, m ):
        giantStep[i] = pow( g, i * m, p )

    for i in range( 0, m ):
        babyStep = ( pow( g, i, p ) * h ) % p
        if babyStep in giantStep:
            index = giantStep.index( babyStep )
            result = index * m - i
            if result < p:
                return result
    return -1

startTime = default_timer()
result = babyStepGiantStepAlgorithm( int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3]) )
print( " Result of Discrete logarithm problem: ", result )
print( " Checking result g^(x) = ", pow( int(sys.argv[1]), result, int(sys.argv[2]) ) )
endTime = default_timer()
print( " Execution time: ", endTime - startTime, "segundos" )
