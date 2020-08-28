#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define fi first
#define se second;
#define ll long long int
using namespace std;
// using namespace __gnu_pbds;
#define bits(x) __builtin_popcount(x)
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {return os << "(" << P.first << "," << P.second << ")";}
template<class T> ostream& operator<<(ostream &os, vector<T> V) {for(auto v : V) os << v << " ";return os<<"";}
template<class T> ostream& operator<<(ostream &os, set<T> S){os << "{ ";for(auto s:S) os<<s<<" ";return os<<"}";}
template<class T> ostream& operator<<(ostream &os, unordered_set<T> S){os << "{ ";for(auto s:S) os<<s<<" ";return os<<"}";}
template<class T> ostream& operator<<(ostream &os, multiset<T> S){os << "{ ";for(auto s:S) os<<s<<" ";return os<<"}";}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {os << "{ ";for(auto m:M) os<<"("<<m.first<<":"<<m.second<<") ";return os<<"}";}
// template<class L, class R> ostream& operator<<(ostream &os, unordered_map<L,R> M) {os << "{ ";for(auto m:M) os<<"("<<m.fi<<":"<<m.se<<") ";return os<<"}";}
template<typename T>
void print(T t){cout<<(t);cout<<'\n';}
template<typename T, typename... Args>
void print(T t, Args... args){cout << (t) <<' ';print(args...);}
void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
vector<vector<int>>g;
vector<ll>calc;
int count(ll x){
    int c=0;
    while(x){
        c+=x&1;
        x>>=1;
    }
    return c;
}
struct segtree{
    int sz;
    vector<ll>tree;
    void init(int n,vector<int>&a){
        sz=1;
        while(sz<=n)sz<<=1;
        tree = vector<ll>(2*sz,0ll);
        build(a,0,0,sz);
    }
    void build(vector<int>&a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<a.size()) tree[x]=(1ll<<a[lx]);
            return;
        }
        int m=(lx+rx)>>1;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        tree[x] = (tree[2*x+1]|tree[2*x+2]);
    }
    void upd(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            tree[x]= 1ll<<v;
            return;
        }
        int m=(lx+rx)/2;
        if(i<m)upd(i,v,2*x+1,lx,m);
        else upd(i,v,2*x+2,m,rx);
        tree[x] = (tree[2*x+1]|tree[2*x+2]);
    }
    void set(int i ,int v){
        upd(i,v,0,0,sz);
    }
    ll get(int l ,int r,int x,int lx,int rx){
        if(lx>=r || rx<=l)return 0;
        if(lx>=l and rx<=r) return tree[x];
        int m=(lx+rx)/2;
        return (get(l,r,2*x+1,lx,m)|get(l,r,2*x+2,m,rx));
    }
    int query(int l,int r){
        return count(get(l,r,0,0,sz));
    }
};
int32_t main()
{
    fileio();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q;cin>>n>>q;
    vector<int>a(n);
    segtree st;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    st.init(n,a);
    for (int i = 0; i < q; ++i)
    {
        int t,x,y;cin>>t>>x>>y;
        x--;
        if(t==1){
            print(st.query(x,y));
        }else{
            st.set(x,y);
        }
    }
    return 0;
}
