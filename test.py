

adj =[[0,1,1,1,0],[1,0,0,0,1],[1,0,0,0,0],[1,0,0,0,1],[0,1,0,1,0]]

adjc = [0]*5

Q = [0]
visited = []
while(len(Q) > 0):
    t = Q.pop(0)
    visited.append(t)
    col = 0
    for i in range(len(adj)):

        if adj[t][i] == 1 and i in adjc:
            if adjc[i] == col:
                col += 1
        
        if adj[t][i] == 1 and i not in visited:
            Q.append(i)
    adjc[t] = col

print(adjc)


