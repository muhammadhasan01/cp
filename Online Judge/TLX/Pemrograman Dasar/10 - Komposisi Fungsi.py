def fungsiKomposisi(A,B,K,x):
    for i in range(1,K+1):
        x = abs(A*x+B)
    return x
a = list(map(int,input().split()))
print(fungsiKomposisi(a[0],a[1],a[2],a[3]))
