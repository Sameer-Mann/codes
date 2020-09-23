#include <bits/stdc++.h>
using namespace std;
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {return os << "(" << P.first << "," << P.second << ")";}
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
int n,m,scc;
vector<vector<int>>g,gr;
vector<int>vis,ordering,compscc;
void dfs(int node){
    vis[node]=1;
    for(auto nbr:g[node]){
        if(!vis[nbr])
            dfs(nbr);
    }
    ordering.push_back(node);
}
void dfs2(int node){
    vis[node]=1;
    compscc[node]=scc;
    for(auto nbr:gr[node]){
        if(!vis[nbr])
            dfs2(nbr);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    g=vector<vector<int>>(n);
    gr=vector<vector<int>>(n);
    compscc=vector<int>(n);
    vis=vector<int>(n,0);
    for (int i = 0; i < m; ++i)
    {
        int u,v;cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        gr[v].push_back(u);
    }
    for (int i = 0; i < n; ++i)
    {
        if(!vis[i])dfs(i);
    }
    reverse(ordering.begin(), ordering.end());
    vis.assign(n,0);
    scc=1;
    for(auto x:ordering)
    {
        if(!vis[x])dfs2(x),scc++;
    }
    print(scc-1);
    print(compscc);
    return 0;
}