a = input().split()
l = []
for i in range(int(a[0])):
	l.append(int(input()))
index = -1
for i in range(len(l)):
	if l[i] == int(a[1]):
		index = i
		break
print(index)