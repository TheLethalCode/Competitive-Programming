def BFS(source, sink, capac, flow):
    
    par = [-1 for i in range(len(flow))]
    par[source] = -2

    queue = [source]

    min_edge = 10**9
    while queue:

        u = queue.pop(0)
        for ind in range(len(flow)):
            
            if not capac[u][ind]:
                continue
            
            if capac[u][ind] - flow[u][ind] > 0 and par[ind] == -1:
                
                par[ind] = u
                min_edge = min(min_edge,capac[u][ind]-flow[u][ind])
                
                if ind == sink:
                    return min_edge, par

                queue.append(ind)

    return 0, par

def solution(entrances, exits, path):

    # Creating a single source and single sink
    for node in range(len(path)):
        path[node].append(0)
        if node not in exits:
            path[node].append(0)
        else:
            path[node].append(10**9)

    entry_row = [0 for node in range(len(path[0]))]
    for node in entrances:
        entry_row[node] = 10**9

    path.append(entry_row)
    path.append([0 for i in range(len(path[0]))])

    # Variables
    n = len(path)
    ans = 0

    # Flow Matrix
    F = [[0 for i in range(n)] for j in range(n)]

    # Execute untill no path remains
    while True:

        flow, par = BFS(n-2,n-1,path,F)
        
        # If no flow is found
        if not flow:
            break

        # Change the flow of system
        ans += flow

        v = n-1
        while v != n-2:
            u = par[v]
            F[u][v] += flow
            F[v][u] -= flow
            v = u

    return ans 
