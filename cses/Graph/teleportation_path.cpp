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
vector<vector<int>>g;
vector<int>indegree,outdegree,ans;
bool iseularian(){
    int st=0,e=0;
    for (int i = 0; i < n; ++i)
    {
        if(abs(indegree[i]-outdegree[i])>1)return 0;
        else if(outdegree[i]-indegree[i]==1)st++;
        else if(indegree[i]-outdegree[i]==1)e++;
    }
    return (e==0 and st==0) or (st==1 and e==1);
}
void dfs(int node){
    int i=0;
    while(outdegree[node]!=0){
        --outdegree[node];
        int x = g[node].back();
        g[node].pop_back();
        dfs(x);
    }
    ans.push_back(node+1);
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    g=vector<vector<int>>(n);
    indegree = vector<int>(n,0);
    outdegree = vector<int>(n,0);
    for (int i = 0; i < m; ++i)
    {
        int u,v;cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        outdegree[u]++;
        indegree[v]++;
    }
    if(!iseularian()){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    dfs(0);
    int fl=1;
    for (int i = 0; i < n; ++i)
    {
        if(outdegree[i]>0)fl=0;
    }
    if(!fl or ans.size()!=m+1 or ans[0]!=n){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    reverse(ans.begin(), ans.end());
    print(ans);
    return 0;
}