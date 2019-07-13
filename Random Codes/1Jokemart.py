a = input().split()
b = eval("+".join(a))
if b%4 == 0:
	b = str(b//4)+",00"
elif b%4 == 1:
	b = str(b//4)+",25"
elif b%4 == 2:
	b = str(b//4)+",50"
else :
	b = str(b//4)+".75"
print("Rp",b)