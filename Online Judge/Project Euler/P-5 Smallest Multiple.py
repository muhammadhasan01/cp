#P-5 Smallest Multiple
"""
Problem-5

Find the smallest positive number that is evenly divisible by all numbers
from range 1 to 20 (included)
"""

#First we'll find the same prime factor from 1 to 20

div = lambda x: [i for i in range(1,x+1) if x%i == 0]
prime = lambda y: True if len(div(y)) == 2 else False
def pdiv(m):
    l = []
    for i in div(m):
        if prime(i):
            l.append(i)
    return l

l = []
for i in range(1,21):
    l += pdiv(i)
sm = map(str,set(l))
print("The smallest multiple from 1-20 is =",eval("*".join(sm)))
