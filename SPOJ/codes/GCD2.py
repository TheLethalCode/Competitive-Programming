import sys, math

T = sys.stdin.readlines()

for case in T[1:]:
    a, b = case.split()
    a = int(a)
    b = int(b)
    print(math.gcd(a,b))