a = input()
b = int(input())
s = ''
for i in a:
    s += chr(ord('a')+(ord(i)+b-ord('a'))%26)
print(s)
