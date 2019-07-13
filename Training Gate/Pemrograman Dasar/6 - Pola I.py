a = list(map(int,input().split()))
l = []
for i in range(1,a[0]+1):
    if i%a[1] == 0:
        l.append("*")
    else:
        l.append(str(i))
print(" ".join(l))
