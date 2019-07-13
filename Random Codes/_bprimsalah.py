def p(n):
	if n == 1:
		return 0
	elif n == 2:
		return 1
	else :
		for i in range(2,int(n**0.5)+1):
			if n%i == 0:
				return 0
		return 1
a = int(input())
for i in range(a):
	b = int(input())
	c = list(map(int,input().split()))
	s = 0
	l = []
	for j in c:
		if j not in l and p(j):
			l.append(j)
	print("Case #"+str(i+1)+":",sum(l))
			
	