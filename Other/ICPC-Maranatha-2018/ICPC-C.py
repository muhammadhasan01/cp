def solve(a):
    memo = [-1]*(len(a)+1)
    return jp(a,memo)
def jp(x,memo):
    y = len(x)
    if memo[y] != -1:
        return memo[y]
    if y == 0:
        memo[y] = 0
        return 0
    elif y == 1:
        memo[y] = 0
        return 0
    elif y == 2:
        memo[y] = x[1]
        return x[1]
    else:
        a,b,c,d,e = -1,-1,-1,-1,-1
        a = jp(x[2:],memo)+x[1]
        b = jp(x[3:],memo)+x[2]
        if len(x) >= 4:
            c = jp(x[4:],memo)+x[3]
        if len(x) >= 5:
            d = jp(x[5:],memo)+x[4]
        if len(x) >= 6:
            e = jp(x[6:],memo)+x[5]
        memo[y] = max(a,b,c,d,e)
        return memo[y]
inp = int(input())
for i in range(1,inp+1):
    a = input()
    l = list(map(int,input().split()))
    print("Case ",i," :",solve(l),sep = '')
    
    
        
