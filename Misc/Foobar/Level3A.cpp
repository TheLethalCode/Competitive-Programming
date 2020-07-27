ans = 0
val = -1

def answer(x,y):

    global ans, val
    if x == 1 and y == 1:
        val = 1
        return

    if x < 1 or y < 1:
        val = 0
        return

    if y == 1:
        ans += x - 1 
        answer(1,1)

    elif x == 1:
        ans += y - 1
        answer(1,1)

    else:
        ans += x/y
        answer(y,x%y)

def solution(x, y):

    global val, ans
    m, n = int(x), int(y)
    if m < 1 or n < 1:
        return "impossible"

    answer(m,n)

    if val == 1:
        return str(ans)

    else:
        return "impossible"
