# Generate the pos
def generate(array_list, array, num, bunnies):
    
    if num == bunnies:
        array_list.append(array)
        return
    
    for i in range(bunnies):
        temp = array[:]
        temp.append(i+1)
        generate(array_list, temp, num+1, bunnies)    
    return


def Floyd_Warshall(times):
    
    n = len(times)

    modify = times

    for k in range(n):
        for i in range(n):
            for j in range(n):
                modify[i][j] = min(modify[i][j],modify[i][k] + modify[k][j])


def solution(times, time_limit):
    
    bunnies = len(times) - 2
    
    array_list = []
    generate(array_list, [], 0, bunnies)

    Floyd_Warshall(times)

    # If there is a negative cycle, all bunnies can be saved
    for i in range(len(times)):
        if times[i][i] < 0:
            return [i for i in range(bunnies)]

    save_size , save_bunny = 0, []
    for array in array_list:

        st, cnt, fi = 0, 0, bunnies + 1 # St - Starting node, cnt - Count the bunnies visited, fi = finishing node
        visited = [-1 for i in range(bunnies + 2)] # Visiting for the bunnies
        temp = time_limit
        
        for node in array:

            # If not visited bunny, increase count and mark visited
            if visited[node] == -1:
                cnt += 1
                visited[node] = 1

            # Decrease the time taken for traversing
            temp -= times[st][node]

            # Update the current bunny
            st = node

        # Go to bulkhead
        temp -= times[st][fi] 

        # If crossed bulhead AND if the current bunnies saved is higher than the original
        if temp >= 0 and cnt > save_size:
            save_size = cnt
            save_bunny = set(array)

    return [i-1 for i in save_bunny]
# 
# print solution([[0, 1, 1, 1, 1], [1, 0, 1, 1, 1], [1, 1, 0, 1, 1], [1, 1, 1, 0, 1], [1, 1, 1, 1, 0]], 3)