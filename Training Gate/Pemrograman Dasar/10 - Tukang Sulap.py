N = int(input())
l = []
for i in range(2):
    l += [input().split()]
Q = int(input())
s = []
for i in range(Q):
    s += [list(map(int,input().replace("A","1").replace("B","2").split()))]
for i in range(Q):
    temp = l[s[i][0]-1][s[i][1]-1]
    l[s[i][0]-1][s[i][1]-1] = l[s[i][2]-1][s[i][3]-1]
    l[s[i][2]-1][s[i][3]-1] = temp
for i in range(2):
    print(" ".join(l[i]))
