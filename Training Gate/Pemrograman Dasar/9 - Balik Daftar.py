from sys import stdin
inp = []
for line in stdin:
    inp.append(line.replace("\n",""))
rinp = inp[::-1]
for i in rinp:
    print(i)
