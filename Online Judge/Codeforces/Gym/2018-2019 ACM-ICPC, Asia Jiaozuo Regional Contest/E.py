N = 100000
sieve = [0 for _ in range(N + 5)]
for i in range(2, N):
    if sieve[i] == 0:
        for j in range(i + i, N, i):
            sieve[j] = 1

primes = []
for i in range(2, N):
    if sieve[i] == 0:
        primes.append(i)

def gcd(x, y):
    if x > y:
        x, y = y, x
    if x == 0:
        return y
    return gcd(y % x, x)

tc = int(input())
for T in range(tc):
    n = int(input())
    res, ser = 1, 1
    for i in range(len(primes)):
        if res * primes[i] > n:
            break
        res *= primes[i]
        ser *= (primes[i] + 1)
    g = gcd(res, ser)
    print(res // g, '/', ser // g, sep = '')