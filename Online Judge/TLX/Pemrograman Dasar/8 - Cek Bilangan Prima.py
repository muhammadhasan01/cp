def prime(a):
    if a == 1:
        return "BUKAN"
    if 1 < a <= 3:
        return "YA"
    for i in range(2,int(a**(1/2))+1):
        if a%i == 0:
            return "BUKAN"
    return "YA"
a = int(input())
for i in range(a):
    print(prime(int(input())))
