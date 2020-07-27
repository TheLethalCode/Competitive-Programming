import sys

T = sys.stdin.readlines()

for stre in T:
    num = int(stre)
    if num!=1:
        print(2*num-2)
    else:
        print(1)