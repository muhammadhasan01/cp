def mul(a, b, mod):
    n = len(a)
    m = len(a[0])
    ret = [[0] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            for k in range(m):
                cur = (a[i][k] % mod) * (b[k][j] % mod)
                cur = (cur % mod + mod) % mod
                ret[i][j] = (ret[i][j] + cur) % mod
                ret[i][j] = (ret[i][j] % mod + mod) % mod
    return ret

I = [[1, 0], [0, 1]]

def modpow(x, k, mod):
    ret = I
    while k > 0:
        if k & 1:
            ret = mul(ret, x, mod)
        k >>= 1
        x = mul(x, x, mod)
    return ret

a, b, m = map(int, input().split())
one = ((a % m) + m) % m
two = (((a * a - 2) % m) + m) % m

if b == 1:
    print(one)
    exit(0)
if b == 2:
    print(two)
    exit(0)

base = [[one, m - 1], [1, 0]]
M = modpow(base, b - 2, m)
res = (M[0][0] * two) % m
res = (res + (M[0][1] * one) % m) % m
print((res % m + m) % m)
