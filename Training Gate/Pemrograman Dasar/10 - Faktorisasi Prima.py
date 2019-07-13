a = int(input())
l,s = [],[]
p,c = 2,0
while(a != 1):
    if a%p == 0:
        if p not in l:
            l.append(p)
        a = a//p
        c += 1
        if a == 1:
            l.append(c)
    else:
        if c >= 1:
            l.append(c)
        p+=1
        c = 0
for i in range(0,len(l),2):
    if l[i+1] >= 2:
        s += [str(l[i])+"^"+str(l[i+1])]
    else:
        s += [str(l[i])]
print(" x ".join(s))
