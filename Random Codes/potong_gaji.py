x = int(input())
for i in range(x):
	a = list(map(int,input().split()))
	l = list(map(int,input().split()))
	k = [i for i in l if i < a[1]//a[0]]
	batas = -1
	if sum(l) > a[1]:
		batas = int((a[1]-sum(k))/(a[0]-len(k)))
	if i != x-1:
	    print(batas)
	else:
		print(batas,end = "")