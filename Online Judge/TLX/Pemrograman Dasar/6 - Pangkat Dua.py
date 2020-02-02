def dp(a):
    if a == 1:
        return "bukan"
    d = [i for i in range(1,a+1) if a%i == 0]
    for i in d:
        if i != 1 and i%2 != 0:
            return "bukan"
    return "ya"
print(dp(int(input())))
