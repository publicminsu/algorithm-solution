import math

n, m, r = map(int, input().split())
b = r - n * m
a = n + b - 1

if n*m > r:
    print(0)
else:
    print(math.factorial(a)//math.factorial(a-b)//math.factorial(b))