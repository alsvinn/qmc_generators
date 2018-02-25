#!/bin/env python
"""
Usage:
    python find_primes.py <outputfile.h>
"""

prime = 2
import sys
def primes1(n):
    """ Returns  a list of primes < n """
    sieve = [True] * (n//2)
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i//2]:
            sieve[i*i//2::i] = [False] * ((n-i*i-1)//(2*i)+1)
    return [2] + [2*i+1 for i in range(1,n//2) if sieve[i]]

number_to_find = 2*1024*1024
number_printed = 0
primes = primes1(number_to_find*32)
number_to_find = len(primes)
with open(sys.argv[2], 'w') as output:
    for n in range(number_to_find):
        output.write("%d " % primes[n])
    output.write("\n")

with open(sys.argv[1], 'w') as output:
    output.write('#define PRIME_MAX %d\n\n' % number_to_find)
    output.write ("static std::vector<int> npvec;\n\n\n")

    output.write("static bool first = true;\n\n")
    output.write("if (first) {\n\n    first = false;\n\n")

    output.write("""
    std::ifstream input_primes("%s");
    npvec.reserve(PRIME_MAX);
    int prime;

    while (input_primes >> prime) {
        npvec.push_back(prime);
    }
}
""" % (sys.argv[2]))
