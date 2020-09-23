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
int n,q;
vector<vector<int>>suc,g;
vector<int>level,vis;
void dfs(int node)
{
    vis[node]=1;
    int child = suc[node][0];
    if(!vis[child])
        dfs(child);
    level[node]=level[child]+1;
}
int climb(int node,int h)
{
    int j=0;
    if(h<=0)return node;
    while(h){
        if(h&1)node = suc[node][j];
        j++,h>>=1;
    }
    return node;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    suc=vector<vector<int>>(n+1,vector<int>(32,0));
    vis= vector<int>(n+2,0);
    level = vector<int>(n+2,0);
    for (int i = 1; i <=n; ++i){
        cin>>suc[i][0];
    }
    for(int i=1;i<32;i++){
        for(int j=1;j<=n;j++)suc[j][i]=suc[suc[j][i-1]][i-1];
    }
    // level[0]=-1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    for (int i = 0; i < q; ++i)
    {
        int u,v;cin>>u>>v;
        if(climb(u,level[u]-level[v])==v)print(level[u]-level[v]);
        else{
            int w=climb(u,level[u]);
            if(climb(w,level[w]-level[v])==v)print(level[u]-level[v]+level[w]);
            else print(-1);
        }
    }
    return 0;
}