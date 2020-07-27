def solution(s):
    ans = 0
    temp = 0
    prefix = []
    for ch in s:
        if ch == '>':
            temp = temp + 1
        prefix.append(temp)

    for ind,ch in enumerate(s):
        if ch == '<':
            ans += prefix[ind] 

    return 2*ans

if __name__ == "__main__":
    print(solution(">-->-->--<--<-->-->--<"))
