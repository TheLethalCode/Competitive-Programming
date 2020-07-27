
soln = [[-1 for i in range(201)] for j in range(201)]

def find(n,done):

    if soln[n][done] == -1 :
        if n <= done:
            return 0

        if n <= 2:
            return 1

        ans = 1
        for step in range(done+1,n+1):
            ans += find(n-step, step)

        soln[n][done] = ans
        return ans

    return soln[n][done]

def solution(n):
    return find(n,0) - 1