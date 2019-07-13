def gcd(a,b):
	if a < b:
		a,b = b,a
	if b == 0 :
		return a
	else :
		return gcd(b,a%b)
a = list(map(int,input().split()))
b = list(map(int,input().split()))
f = gcd(a[0]*b[1]+a[1]*b[0],a[1]*b[1])
print((a[0]*b[1]+a[1]*b[0])//f,a[1]*b[1]//f)