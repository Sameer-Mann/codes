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
int n,m;
vector<set<int>>g;
vector<int>ans;
void dfs(int node)
{
    while(g[node].size()){
        int nbr = *(g[node].begin());
        g[node].erase(g[node].begin());
        g[nbr].erase(g[nbr].find(node));
        dfs(nbr);
    }
    ans.push_back(node+1);
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    g=vector<set<int>>(n);
    for (int i = 0; i < m; ++i)
    {
        int u,v;cin>>u>>v;
        u--,v--;
        g[u].insert(v);
        g[v].insert(u);
    }
    int ct=0;
    for (int i = 0; i < n; ++i)ct+=(g[i].size()%2);
    dfs(0);
    if((int)ans.size()!=m+1 or ct or ans.back()!=1){
        print("IMPOSSIBLE");
        return 0;
    }
    print(ans);
    return 0;
}