pow_b = []

def calc(n,k):

    ans = 0
    for ind,num in enumerate(n):
        ans += int(num)*pow_b[k-ind-1]
    return ans

def func(n,b):
    k = len(n)
    z = calc(sorted(n,reverse=True),k) - calc(sorted(n),k)
    ans = ""
    i = 0
    while i < k:
        ans += str(z%b)
        z/=b
        i += 1
    return ans[::-1]

def solution(n,b):
    
    init = 1
    for i in range(10):
        pow_b.append(init)
        init*=b

    maps = {}
    ans = 0    
    while maps.get(n) is None:
        maps[n] = ans
        n = func(n,b)
        ans += 1
    return ans - maps[n]

if __name__ == "__main__":
    print(solution('210022', 3))
