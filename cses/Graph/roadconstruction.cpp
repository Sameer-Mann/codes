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
int n,m,comps,max_size;
vector<int>par,comp_size;
int find(int u){
    if(par[u]==u or par[u]==-1){
        return par[u]=u;
    }
    return find(par[u]);
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    comps=n,max_size=1;
    par=vector<int>(n+1,-1);
    comp_size=vector<int>(n+1,1);
    for (int i = 0; i < m; ++i)
    {
        int a,b;cin>>a>>b;
        int p1=find(a),p2=find(b);
        if(p1!=p2){
            comps--;
            if(comp_size[p1]<comp_size[p2]){
                comp_size[p2]+=comp_size[p1];
                par[p1]=p2;
                max_size=max(max_size,comp_size[p2]);
            }else{
                comp_size[p1]+=comp_size[p2];
                par[p2]=p1;
                max_size=max(max_size,comp_size[p1]);
            }
        }
        print(comps,max_size);
    }
    return 0;
}