def agprima(a):
    c = 0
    for i in range(1,int(a**(1/2))+1):
        if a%i == 0:
            c+=1
        if c > 2:
            return "BUKAN"
    return "YA"
for i in range(int(input())):
    print(agprima(int(input())))
    
        
