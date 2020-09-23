#include <bits/stdc++.h>
#define int long long int
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
int n,m,numofscc;
const int N = 1e5+1;
int cost[N],compscc[N],compval[N],vis[N],dp[N];
vector<int>adj1[N],adj2[N],ordering;
vector<vector<int>>adj3;
void dfs(int node)
{
    vis[node]=1;
    for(auto nbr:adj1[node]){
        if(!vis[nbr])
            dfs(nbr);
    }
    ordering.push_back(node);
}
void dfs2(int node)
{
    vis[node]=1;
    compscc[node]=numofscc;
    compval[numofscc]+=cost[node];
    for(auto nbr:adj2[node]){
        if(!vis[nbr])
            dfs2(nbr);
    }
}
int f(int node)
{
    if(dp[node]!=-1)return dp[node];
    int ans = 0;
    for(auto nbr:adj3[node]){
        ans = max(ans,f(nbr));
    }
    return dp[node] = ans+compval[node];
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i = 0; i < N; ++i)
    {
        cost[i]=compval[i]=compscc[i]=vis[i]=0;
        dp[i]=-1;
        adj1[i].clear();
        adj2[i].clear();
    }
    for (int i = 1; i <= n; ++i)cin>>cost[i];
    for (int i = 0; i < m; ++i)
    {
        int u,v;cin>>u>>v;
        adj1[u].push_back(v);
        adj2[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
    {
        if(!vis[i])dfs(i);
    }
    reverse(ordering.begin(), ordering.end());
    memset(vis,0,sizeof(vis));
    numofscc=0;
    for(auto x:ordering)
    {
        if(!vis[x])
            dfs2(x),numofscc++;
    }
    adj3=vector<vector<int>>(numofscc+1);
    for (int i = 1; i <= n; ++i)
    {
        for(auto x:adj1[i]){
            if(compscc[i]!=compscc[x])adj3[compscc[i]].push_back(compscc[x]);
        }
    }
    int ans = 0;
    for (int i = 0; i < numofscc; ++i)
    {
        ans = max(ans,f(i));
    }
    // print(adj1);
    // for (int i = 0; i <= n; ++i)
    // {
    //     // cout<<compscc[i]<<" ";
    // //     // print(adj3[i]);
    //     print(adj3[i]);
    // }
    // cout<<endl;
    print(ans);
    return 0;
}