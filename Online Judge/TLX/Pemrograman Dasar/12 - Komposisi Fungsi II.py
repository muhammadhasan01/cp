def fK(A,B,K,x):
    if K == 1:
        return abs(A*x+B)
    else:
        return fK(A,B,1,fK(A,B,K-1,x))
a = list(map(int,input().split()))
print(fK(a[0],a[1],a[2],a[3]))
