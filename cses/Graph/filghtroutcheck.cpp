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
vector<vector<int>>gr;
map<int,set<int>>g;
vector<int>vis,ordering;
void dfs(int node)
{
    vis[node]=1;
    for(auto nbr:g[node]){
        if(!vis[nbr])
            dfs(nbr);
    }
    ordering.push_back(node);
}
void dfs2(int node){
    vis[node]=1;
    for(auto nbr:gr[node]){
        if(!vis[nbr])
            dfs2(nbr);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    // g=vector<vector<int>>(n);
    gr=vector<vector<int>>(n);
    vis=vector<int>(n);
    for (int i = 0; i < m; ++i)
    {
        int u,v;cin>>u>>v;
        u--,v--;
        g[u].insert(v);
        gr[v].push_back(u);
    }
    for (int i = 0; i < n; ++i)
    {
        if(!vis[i])dfs(i);
    }
    reverse(ordering.begin(), ordering.end());
    // print(ordering);
    scc=0;
    fill(vis.begin(), vis.end(),0);
    dfs2(ordering[0]);
    // print(vis);
    int u=-1,v=-1,fl=0;
    for (int i = 0; i < n; ++i)
    {
        if(!vis[i]){
            fl=1;
            u=i;
            break;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if(vis[i] and !g[i].count(v)){
            v=i;
            break;
        }
    }
    if(!fl)print("YES");
    else{
        print("NO");
        print(u+1,v+1);
    }
    return 0;
}