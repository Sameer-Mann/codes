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
int n,m,k,ans;
vector<vector<int>>g;
bool h(int u,int vis[],int match[])
{
    for (int i = 1; i <= m; ++i)
    {
        if(g[u][i] and !vis[i]){
            vis[i]=1;
            if(match[i]==-1 or h(match[i],vis,match)){
                match[i]=u;
                return 1;
            }
        }
    }
    return 0;
}
void f()
{
    int match[m+1];
    memset(match,-1,sizeof(match));
    for (int i = 1; i <= n; ++i)
    {
        int vis[m+1];
        memset(vis,0,sizeof(vis));
        ans += h(i,vis,match);
    }
    print(ans);
    for (int i = 1; i <= m; ++i) if(match[i]!=-1)print(match[i],i);
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    g=vector<vector<int>>(n+1,vector<int>(m+1,0));
    for (int i = 0; i < k; ++i)
    {
        int u,v;cin>>u>>v;
        g[u][v]=1;
    }
    f();
    return 0;
}