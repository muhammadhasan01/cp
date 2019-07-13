def yesorno(a,k):
    if k == 0:
        return "YES"
    for i in range(1,int(k**.5)+1):
        if k%i==0 :
            x,c = i,0
            for j in a:
                x -= int(j)
                if x==0:
                    x=i
                    c+=1
                elif x<0:
                    c = 0
                    break
            if c>=2:
                return "YES"
            x,c = k//i,0
            for j in a:
                x -= int(j)
                if x==0:
                    x=k//i
                    c+=1
                elif x<0:
                    c = 0
                    break
            if c>=2:
                return "YES"
    return "NO"

n = int(input())
a = str(input())
k = 0
for i in a:
    k+=int(i)
print(yesorno(a,k))

            
