i = int(input())
for i in range(i):
	a = list(map(int,input().split()))
	if a[0] == a[1] :
		print(a[0])
	elif 2*a[1] == a[0]+a[2] :
		print(3*a[1]-2*a[0])
	elif a[1]**2 == a[0]*a[2] :
		print(a[1]**3//a[0]**2)