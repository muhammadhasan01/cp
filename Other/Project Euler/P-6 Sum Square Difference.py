#P-6 Sum square difference

"""
Find the difference between
the sum of the squares of the first one hundred natural numbers
and the square of the sum.

Example :
From the first 3 natural numbers would be
(1+2+3)^2-(1^2+2^2+3^2) = 22
"""

sum_square = []
square_sum = []
for i in range(1,101):
    sum_square.append(i)
    square_sum.append(i**2)
print("The result is",sum(sum_square)**2-sum(square_sum))
    
