#include <bits/stdc++.h>
using namespace std;
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {return os << P.first << " " << P.second;}
template<class T> ostream& operator<<(ostream &os, vector<T> V) {for(auto v : V) os << v << " ";return os<<"";}
template<class T> ostream& operator<<(ostream &os, set<T> S){os << "{ ";for(auto s:S) os<<s<<" ";return os<<"}";}
template<class T> ostream& operator<<(ostream &os, unordered_set<T> S){os << "{ ";for(auto s:S) os<<s<<" ";return os<<"}";}
template<class T> ostream& operator<<(ostream &os, multiset<T> S){os << "{ ";for(auto s:S) os<<s<<" ";return os<<"}";}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {os << "{ ";for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";return os<<"}";}
template<class L, class R> ostream& operator<<(ostream &os, unordered_map<L,R> M) {os << "{ ";for(auto m:M) os<<"("<<m.fi<<":"<<m.se<<") ";return os<<"}";}
template<typename T>
void print(T t){cout<<(t);cout<<'\n';}
template<typename T, typename... Args>
void print(T t, Args... args){cout << (t) <<' ';print(args...);}
int n,m;
vector<vector<int>>g,graph;
vector<bool>instack;
// vector<int>tin,tout;
void dfs(int node,int p){
    if(node == n-1){
        graph[p][node]=1;
        return;
    }
    instack[node]=1;
    if(p!=-1){
        graph[p][node]=1;
    }
    for(auto nbr:g[node]){
        if(!instack[nbr]){
            dfs(nbr,node);
        }
    }
    // instack[node]=0;
}
int bfs(vector<vector<int>>&rGraph, int s, int t, int parent[]) 
{
    bool visited[n]; 
    memset(visited, 0, sizeof(visited)); 
    queue <int> q; 
    q.push(s); 
    visited[s] = true; 
    parent[s] = -1; 
    while (!q.empty()) 
    { 
        int u = q.front(); 
        q.pop(); 
  
        for (int v=0; v<n; v++) 
        { 
            if (visited[v]==false && rGraph[u][v] > 0) 
            { 
                q.push(v); 
                parent[v] = u; 
                visited[v] = true; 
            } 
        }
    }
    return (visited[t] == true); 
}
void dfs(vector<vector<int>>&rGraph, int s, bool visited[]) 
{ 
    visited[s] = true; 
    for (int i = 0; i < n; i++) 
       if (rGraph[s][i] && !visited[i]) 
           dfs(rGraph, i, visited); 
} 
void minCut(int s, int t) 
{ 
    int u, v; 
    vector<vector<int>>rGraph(n,vector<int>(n,0));
    for (u = 0; u < n; u++) 
        for (v = 0; v < n; v++) 
             rGraph[u][v] = graph[u][v]; 
  
    int parent[n];
    while (bfs(rGraph, s, t, parent)) 
    { 
        int path_flow = INT_MAX; 
        for (v=t; v!=s; v=parent[v]) 
        { 
            u = parent[v]; 
            path_flow = min(path_flow, rGraph[u][v]); 
        } 
        for (v=t; v != s; v=parent[v]) 
        { 
            u = parent[v]; 
            rGraph[u][v] -= path_flow; 
            rGraph[v][u] += path_flow; 
        } 
    }
    bool visited[n]; 
    memset(visited, false, sizeof(visited)); 
    dfs(rGraph, s, visited);
    vector<pair<int,int>>ans;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         if (visited[i] && !visited[j] && graph[i][j]){
            ans.push_back(make_pair(i+1,j+1));
            }
        }
    }
    print(ans.size());
    for(auto x:ans){
        print(x);
    }
    return; 
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    g = vector<vector<int>>(n);
    graph = vector<vector<int>>(n,vector<int>(n,0));
    // tin = vector<int>(n,0);
    // tout =  vector<int>(n,0);
    for (int i = 0; i < m; ++i)
    {
        int u,v;cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
        graph[u][v]=1;
        graph[v][u]=1;
    }
    instack = vector<bool>(n,0);
    // dfs(0,-1);
    minCut(0,n-1);
    // print(graph);
    return 0;
}