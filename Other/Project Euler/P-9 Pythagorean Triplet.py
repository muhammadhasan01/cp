#P-9 Special Pythagorean Triplet

"""
A pythagorean triplet a<b<c has a sum of 1000 (a+b+c = 1000)
find the product of abc
"""

#a^2-b^2,2ab,a^2+b^2
i = 2
l = []
while(i < 10):
    for j in range(i-1,0,-1):
        a = i**2-j**2
        b = 2*i*j
        c = i**2+j**2
        l += [a,b,c]
        print(l)
        if a+b+c == 1000:
            break
    i += 1
        
    
