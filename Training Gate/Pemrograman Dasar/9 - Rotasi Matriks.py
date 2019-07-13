a = list(map(int,input().split()))
l = []
for i in range(a[0]):
    j = input().split()
    l+= [[i for i in j]]
for i in range(a[1]):
    m = []
    for j in range(a[0]):
        m += [l[j][i]]
    print(" ".join(m[::-1]))

    
