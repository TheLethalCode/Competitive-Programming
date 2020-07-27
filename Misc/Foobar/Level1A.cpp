def solution(s):
    maps = {}
    maps['a'] = "100000"
    maps['b'] = "110000"
    maps['c'] = "100100"
    maps['d'] = "100110"
    maps['e'] = "100010"
    maps['f'] = "110100"
    maps['g'] = "110110"
    maps['h'] = "110010"
    maps['i'] = "010100"
    maps['j'] = "010110"
    maps['k'] = "101000"
    maps['l'] = "111000"
    maps['m'] = "101100"
    maps['n'] = "101110"
    maps['o'] = "101010"
    maps['p'] = "111100"
    maps['q'] = "111110"
    maps['r'] = "111010"
    maps['s'] = "011100"
    maps['t'] = "011110"
    maps['u'] = "101001"
    maps['v'] = "111001"
    maps['w'] = "010111"
    maps['x'] = "101101"
    maps['y'] = "101111"
    maps['z'] = "101011"
    maps["cap"] = "000001"
    maps[" "] = "000000"
    ans = ""
    for ch in s:
        if ord(ch) >= 65 and ord(ch) <= 90:
            ans= ans + maps["cap"]
        ans = ans + maps[ch.lower()]
    return ans