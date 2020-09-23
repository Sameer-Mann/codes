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
int n;
vector<int>ans,vis,level;
vector<vector<int>>g;
void dfs(int node,int par,map<int,int>&instack)
{
    vis[node]=1;
    instack[node]=instack.size()+1;
    for(auto x:g[node])
    {
        if(vis[x])
        {
            int st = x,len=abs(instack[st]-instack[node])+1;
            if(ans[x]==-1)
            {
                for(auto &v:instack)
                {
                    if(ans[v.first]==-1)
                    {
                        ans[v.first]=len + ((v.second<instack[st])?abs(instack[st]-v.second):0);
                    }
                }
            }else{
                for(auto &v:instack){
                    if(ans[v.first]==-1)ans[v.first]=v.second+len+1;
                }
            }
            return;
        }
        else dfs(x,node,instack);
    }
    instack.erase(instack.find(node));
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    g=vector<vector<int>>(n);
    ans=vector<int>(n,-1);
    vis=vector<int>(n,0);
    level=vector<int>(n,0);
    for (int i = 0; i < n; ++i)
    {
        int v;cin>>v;
        g[i].push_back(--v);
    }
    for (int i = 0; i < n; ++i)
    {
        if(!vis[i]){
            map<int,int>instack;
            dfs(i,i,instack);
        }
    }
    print(ans);
    return 0;
}