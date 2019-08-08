def kBiner(num):
    if num == 1:
        return "1"
    if num%2 == 0:
        return kBiner(num//2)+"0"
    else:
        return kBiner(num//2)+"1"
inp = int(input())
print(kBiner(inp))
    
