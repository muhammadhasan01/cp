def ovf(a):
    if a == 1 or a == 2:
        return 1
    else:
        if a%2 == 0:
            return (a//2)*ovf(a-1)
        else:
            return a*ovf(a-1)
a = int(input())
print(ovf(a))
