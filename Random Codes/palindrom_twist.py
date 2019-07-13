def pt(a):
    x = len(a)
    for i in range(x//2):
        if abs(ord(a[i])-ord(a[x-1-i])) > 2:
            return "NO"
    return "YES"
for i in range(int(input())):
    useless = input()
    print(pt(input()))
