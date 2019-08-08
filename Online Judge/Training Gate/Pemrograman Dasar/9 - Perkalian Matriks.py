a = list(map(int,input().split()))
m1 = []
for i in range(a[0]):
    m1 += [input().split()]

m2 = []
for i in range(a[1]):
    m2 += [input().split()]
for i in range(a[0]):
    m3 = []
    for j in range(a[2]):
        s = 0
        for k in range(a[1]):
            s += int(m1[i][k])*int(m2[k][j])
        m3 += [str(s)]
    print(" ".join(m3))
