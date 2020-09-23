import sys
ip = lambda :sys.stdin.readline().rstrip('\r\n')
n,m = map(int,ip().split())
g = [[] for _ in range(n)]
ways = [0]*(n)
vis = [0]*(n)
edges = [[0]*(n) for _ in range(n)]
ans = []
for _ in range(m):
    u,v = map(int,ip().split())
    v-=1;u-=1
    g[u].append(v)
    edges[u][v]=1;
def dfs(node):
    if node == n-1:
        return 1
    vis[node]=1;
    for nbr in g[node]:
        if not vis[nbr]:
            ways[node]+=dfs(nbr);
        else:
            ways[node]+=ways[nbr]
    return ways[node];
def f(node,par,path):
    if node == n-1:
        if not edges[path[-1]][node]:
            return False
        edges[path[-1]][node]=0
        ans.append([])
        for x in path:
            ans[-1].append(x+1)
        ans[-1].append(n)
        return True;
    vis[node]=1;
    fl=0
    path.append(node)
    if ways[node]:
        if par != -1:
            edges[par][node]=0
        for nbr in g[node]:
            if not vis[nbr] and edges[node][nbr]:
                if f(nbr,node,path) and node!=0:
                    fl=1
                    break
    path.pop()
    vis[node]=0
    return fl;
dfs(0)
for i in range(n):
    g[i].sort(key = lambda x:ways[x])
vis = [0]*(n)
f(0,0,[])
print(len(ans))
for i in ans:
    print(len(i))
    print(*i)