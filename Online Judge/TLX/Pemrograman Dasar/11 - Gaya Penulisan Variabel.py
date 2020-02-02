a = input()
s = ""
cond = False
for i in a:
    if i.isupper():
        cond = True
if "_" in a:
    b = a.split("_")
    if len(b) >= 2:
        b = [b[0]]+[(b[i][0]).upper()+b[i][1:] for i in range(1,len(b))]
    print("".join(b))
elif cond:
    for i in a:
        if i.isupper():
            s+="_"+i.lower()
        else:
            s+=i
    print(s)
else:
    print(a)
