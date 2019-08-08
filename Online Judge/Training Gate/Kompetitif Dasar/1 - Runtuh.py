a = list(map(int,input().split()))
if a[0] == 1:
    print(input())
else:
 l = []
 for i in range(a[0]):
    x = input()
    if x == "1"*a[1]:
        l = ["0"*a[1]]+l
    else :
        l.append(x)
 print(l)
 for j in range(a[0]-1):
     for i in range(a[1]):
         print(l[i][j],l[i][j] > l[i+1][j],i,j)
         if l[i][j] > l[i+1][j]:
             l[i] = l[i][:j]+"0"+l[i][j+1:]
             l[i+1] = l[i+1][:j]+"1"+l[i+1][j+1:]
             print(l,l[i+1])
             if l[i+1] == "1"*a[1]:
                 l = ["0"*a[1]]+l[:i+1]+l[i+2:]
                 print(l, "*NEW*")
 print(l)

"""
5 3
111
110
010
011
111
"""
