import math

n, m, r = map(int, input().split())
a = n + r - m * n - 1
b = r - n * m

if n*m > r:
    print(0)
else:
    print(math.factorial(a)//math.factorial(a-b)//math.factorial(b))