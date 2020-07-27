from collections import Counter as cnt

def fact(n):
    ans = 1
    for i in range(2,n+1):
        ans *= i
    return ans


def gcd(x,y):
    if y == 0:
        return x
    return gcd(y,x%y)


def rand_cyc(c, n):
    temp = fact(n)
    for a, b in cnt(c).items():
        temp /= (a**b)*fact(b)
    return temp        


def partitions(n, i=1):
    yield [n]
    for i in range(i, n/2 + 1):
        for part in partitions(n-i, i):
            yield [i] + part


def solution(w, h, s):    
    
    ans=0
    
    for w_cyc in partitions(w):
        for h_cyc in partitions(h):            
            m = rand_cyc(w_cyc, w)*rand_cyc(h_cyc, h)
            ans += m * (s ** sum( [ sum( [ gcd(i, j) for i in w_cyc ] ) for j in h_cyc ] ))
              
    return ans/(fact(w)*fact(h))