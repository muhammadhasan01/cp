x = input().split(' ');
n, s = int(x[0]), int(x[1])
l = []
for i in range(n):
    temp = input().split(' ')
    name, value = temp[0], int(temp[1])
    l.append((value, name))
l.sort()
l.reverse()
answer = []
for i in range(n):
    if l[i][0] > s:
        continue
    s -= l[i][0]
    answer.append(l[i][1])

if s != 0:
    print(0)
else:
    print(len(answer))
    for x in answer:
        print(x)