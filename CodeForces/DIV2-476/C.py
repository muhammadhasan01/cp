a = input().split(' ')
n = int(a[0])
k = int(a[1])
m = int(a[2])
d = int(a[3])

ans = 0
for i in range(1,d+1):
    l,r,x = 1,m,-1
    cur = (i - 1) * k + 1
    while(l <= r):
        mid = (l+r)//2
        if n//mid >= cur :
            l = mid + 1
            x = mid
        else:
            r = mid - 1
    if x == -1 or n//x > i * k:
        continue
    if x * i > ans :
        ans = x * i
print(int(ans))
