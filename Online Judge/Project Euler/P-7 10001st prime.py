#P-7 The 10001st prime

"""
Problem:
Find the 10001st prime if 2 is the first prime
"""

#Solution from stackexchange

def primes(n):
    primes = [2]
    attempt = 3
    while len(primes) < n:
        if all(attempt % prime != 0 for prime in primes):
            primes.append(attempt)
        attempt += 2
    return primes[-1]

print(primes(10001))
