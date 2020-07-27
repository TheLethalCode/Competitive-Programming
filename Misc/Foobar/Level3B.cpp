from fractions import Fraction

def gcd(a,b):
    if not b:
        return a

    return gcd(b,a%b)

def mult(A,B):

    x = len(A)
    y = len(B)
    z = len(B[0])

    ans = [[0 for i in range(z)] for j in range(x)]
    for i in range(x):
        for j in range(z):
            for k in range(y):
                ans[i][j] += A[i][k] * B[k][j]

    return ans

def minorMat(m,r,c):
    return [ (row[:c] + row[c+1:]) for row in (m[:r] + m[r+1:]) ]

def getDeterminant(m):

    if len(m) == 2:
        return (m[0][0]*m[1][1] - m[1][0]*m[0][1])

    ans = 0
    for i in range(len(m)):
        ans += ((-1)**i)*m[0][i]*getDeterminant(minorMat(m,0,i))
    return ans

def inverse(m):

    if len(m) == 1:
        return [[1/m[0][0]]]

    D = getDeterminant(m)

    if len(m) == 2:
        return [ [Fraction(m[1][1],D), Fraction(-1*m[0][1],D)],
                 [Fraction(-1*m[1][0],D), Fraction(m[0][0],D)] ]

    cofactorMatrix = [[0 for i in m] for j in m]
    for r in range(len(m)):
        for c in range(len(m)):
            cofactorMatrix[c][r] = Fraction(((-1)**(r+c))*getDeterminant(minorMat(m,r,c)),D)

    return cofactorMatrix
    

def solution(graph):
    
    n =  len(graph)

    if n == 1:
        return [1,1]
    
    terminals = [i for i in range(n) if not sum(graph[i])]
    non_terminals = [i for i in range(n) if sum(graph[i])]

    t = len(non_terminals)
    s = len(terminals)

    T = [[0 for i in range(t)] for j in range(t)]
    R = [[0 for i in range(len(terminals))] for j in range(t)]
    I = [[0 for i in range(t)] for j in range(t)]
    temp_mat = I

    for i in range(t):
        I[i][i] = 1

    for ind, trans in enumerate(non_terminals):
        temp = sum(graph[trans])
        for ind1, trans1 in enumerate(non_terminals):
            T[ind][ind1] = Fraction(graph[trans][trans1],temp)
    
    for ind, trans in enumerate(non_terminals):
        temp = sum(graph[trans])
        for ind1, trans1 in enumerate(terminals):
            R[ind][ind1] = Fraction(graph[trans][trans1],temp)

    for i in range(t):
        for j in range(t):
            temp_mat[i][j] = I[i][j] - T[i][j]

    Q = inverse(temp_mat)
    N = mult(Q,R)

    lcm = 1
    for prob in N[0]:
       lcm = ( prob.denominator * lcm ) / ( gcd(lcm, prob.denominator) )

    ans = [prob.numerator * (lcm / prob.denominator ) for prob in N[0]]
    ans.append(lcm)
    return ans