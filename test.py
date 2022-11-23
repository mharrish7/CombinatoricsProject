

n = int(input("Enter the no \n"))
adj = []
for i in range(n):
    temp = list(map(int,input().split()))
    adj.append(temp)

adjc = [-1]*n

Q = [0]
visited = []
while(len(Q) > 0):
    t = Q.pop(0)
    print(Q)
    visited.append(t)
    col = 0
    aval = [-1]*n
    for i in range(len(adj)):
        if adj[t][i] == 1 and adjc[i] != -1:
            if t==4:
                print(adj[t],adjc)
            aval[adjc[i]] = 1
        
        if adj[t][i] == 1 and i not in visited:
            Q.append(i)
    for i in aval:
        if i != -1:
            col = i
            break
    print(aval)
    adjc[t] = col

print(adjc)


