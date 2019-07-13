def pot(a):
    if a[0] > a[1]:
        if a[1]%2 == 0:
            return a[1]//2-1
        else:
            return a[1]//2
    elif a[0] == a[1]:
        return 0
    else:
        if 2*a[0]-1 >= a[1]:
            return (2*a[0]-a[1]+1)//2
        else:
            return 0
a = list(map(int,input().split()))
print(pot(a))
        
