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
struct item{
    vector<ll>a;
    ll inv;
    item(){
        a.assign(42,0ll);
        inv=0;
    }
};
struct segtree{
    int sz;
    vector<item>tree;
    void init(int n,vector<int>&a){
        sz=1;
        while(sz<=n)sz<<=1;
        tree = vector<item>(2*sz);
        build(a,0,0,sz);
    }
    item merge(item a,item b){
        item c;
        vector<ll>pref(42,0ll);
        for(int i=40;i>=0;i--) pref[i] += pref[i+1]+a.a[i];
        for (int i = 1; i <=40 ; ++i) c.inv += pref[i+1]*b.a[i];
        c.inv += a.inv+b.inv;
        for (int i = 1; i <=40 ; ++i) c.a[i]+=a.a[i]+b.a[i];
        return c;
    }
    void build(vector<int>&a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<a.size()){
                tree[x].a[a[lx]]=1;
            }
            return;
        }
        int m=(lx+rx)>>1;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        tree[x] = merge(tree[2*x+1],tree[2*x+2]);
    }
    void upd(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            tree[x].a = vector<ll>(42,0ll);
            tree[x].a[v]=1;
            return;
        }
        int m=(lx+rx)/2;
        if(i<m)upd(i,v,2*x+1,lx,m);
        else upd(i,v,2*x+2,m,rx);
        tree[x] = merge(tree[2*x+1],tree[2*x+2]);
    }
    void set(int i ,int v){
        upd(i,v,0,0,sz);
    }
    item get(int l ,int r,int x,int lx,int rx){
        if(lx>=r || rx<=l)return item();
        if((lx>=l and rx<=r)||(rx-lx)==1)return tree[x];
        int m=(lx+rx)/2;
        return merge(get(l,r,2*x+1,lx,m),get(l,r,2*x+2,m,rx));
    }
    ll query(int l,int r){
        return get(l,r,0,0,sz).inv;
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
