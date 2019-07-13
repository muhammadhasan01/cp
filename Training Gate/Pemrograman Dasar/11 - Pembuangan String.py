a = input().split()
while(a[1] in a[0]):
    a[0] = a[0].replace(a[1],"")
print(a[0])
