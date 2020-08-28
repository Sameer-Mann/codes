#include <bits/stdc++.h>
// #define int long long int
#define bits(x) __builtin_popcount(x)
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
vector<int>a;
int n;
struct segtree {
    int sz=1;
    vector<int>tree;
    void init(){
        sz=1;
        while(sz<=n)sz<<=1;
        tree.assign(2*sz,0);
        build(0,0,sz);
    }
    void build(int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<n and a[lx])tree[x]=1;
            return;
        }
        int mid = (lx+rx)>>1;
        build(2*x+1,lx,mid);
        build(2*x+2,mid,rx);
        tree[x] = tree[2*x+1]+tree[2*x+2];
    }
    void update(int i,int x,int lx,int rx){
        if(rx-lx==1){
            tree[x]^=1;
            return;
        }
        int mid = (lx+rx)>>1;
        if(i<mid)update(i,2*x+1,lx,mid);
        else update(i,2*x+2,mid,rx);
        tree[x] = tree[2*x+1]+tree[2*x+2];
    }
    int get(int k,int x,int lx,int rx){
        if(rx-lx==1)return lx;
        int mid = (lx+rx)>>1;
        if(k<tree[2*x+1]) return get(k,2*x+1,lx,mid);
        return get(k-tree[2*x+1],2*x+2,mid,rx);
    }
}st;
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m;cin>>n>>m;
    a=vector<int>(n);
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    st.init();
    for (int i = 0; i < m; ++i)
    {
        int t,k;cin>>t>>k;
        if(t==1)st.update(k,0,0,st.sz);
        else print(st.get(k,0,0,st.sz));
    }
    return 0;
}
