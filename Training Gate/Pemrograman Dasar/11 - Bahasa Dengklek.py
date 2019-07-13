a = input()
s = ''
for i in a:
    if i.isupper():
        s += i.lower()
    else:
        s += i.upper()
print(s)
