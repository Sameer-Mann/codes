#include <bits/stdc++.h>
#define ll long long int
#define pi pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
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
void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
struct segtree
{
    int size;
    vector<ll> tree;
    // in a range l to r r is always excluded
    void init(int n){
        size=1;
        while(size<n)size*=2;
        tree  = vector<ll>(2*size,0ll);
    }
    void build(vector<ll> &a,int x ,int lx, int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()){
                tree[x]=a[lx];
            }
            return;
        }
        int m = (lx+rx)>>1;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        tree[x]=tree[2*x+1]+tree[2*x+2];
    }
    void build(vector<ll>&a){
        build(a,0,0,size);
    }
    void update(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            tree[x]=((i&1)?-1:1)*v;
            return;
        }
        int m=(lx+rx)>>1;
        if(i<m) update(i,v,2*x+1,lx,m);
        else update(i,v,2*x+2,m,rx);
        tree[x]=tree[2*x+1]+tree[2*x+2];
    }
    void set(int i,int v){
        update(i,v,0,0,size);
    }
    ll query(int l,int r,int x,int lx,int rx){
        if(lx>=r || rx<=l)return 0;
        if(lx>=l and rx<=r)return tree[x];
        int m = (lx+rx)>>1;
        return query(l,r,2*x+1,lx,m)+query(l,r,2*x+2,m,rx);
    }
    ll query(int l,int r){
        return ((l&1)?-1:1)*query(l,r+1,0,0,size);
    }
};
int32_t main()
{
    fileio();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;cin>>n;
    vector<ll>a(n);
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        if(i&1)a[i]*=-1;
    }
    segtree st;
    st.init(n);
    st.build(a);
    int m;cin>>m;
    for (int i = 0; i < m; ++i)
    {
        int t;cin>>t;
        if(t==0){
            int k,v;cin>>k>>v;
            k--;
            st.set(k,v);
        }else{
            int l,r;cin>>l>>r;
            l--,r--;
            print(st.query(l,r));
        }
    }
    return 0;
}

