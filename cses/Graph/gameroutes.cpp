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
int n,m,mod = 1e9+7;
vector<vector<int>>g;
vector<int>dp;
int dfs(int node)
{
    if(node==n-1)return 1;
    if(dp[node]!=-1)return dp[node];
    dp[node]=0;
    for(auto nbr:g[node]) dp[node]=(dp[node] +dfs(nbr))%mod;
    dp[node]++;
    dp[node]%=mod;
    return dp[node];
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    g=vector<vector<int>>(n);
    dp = vector<int>(n,-1);
    for (int i = 0; i < n; ++i)
    {
        int u,v;cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
    }
    print(dfs(0));
    return 0;
}