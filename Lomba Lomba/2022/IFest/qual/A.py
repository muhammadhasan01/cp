def C(n, k):
    res = 1
    if k > n - k:
        k = n - k;
    for i in range(k):
        res *= (n - i);
        res //= (i + 1);
    return res;

l = int(input())
r = int(input())

up = r
for i in range(l, r + 1):
    print(" " * (r - i), end='')
    for j in range(i + 1):
        print(C(i, j), end='')
        if j == i and i < r:
            print()
        else:
            print(" ", end='')