#include <bits/stdc++.h>
#define int long long int
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
int n;
int a[100000];
struct segtree {
    int sz;
    int** tree;
    void init(){
        sz=1;
        while(sz<=n)sz<<=1;
        // pref,suf,sum,mx
        tree = new int*[2*sz];
        for (int i = 0; i < 2*sz; ++i){
            tree[i] = new int[4];
            tree[i][0]=tree[i][1]=tree[i][2]=tree[i][3]=0;
        }
        build(0,0,sz);
    }
    int* merge(int* a,int* b){
        int* c= new int[4];
        c[2] = a[2]+b[2];
        c[0] = max(max(a[0],a[2]+b[0]),0ll);
        c[1] = max(max(b[1],a[1]+b[2]),0ll);
        c[3] = max(max(max(a[3],b[3]),a[1]+b[0]),0ll);
        return c;
    }
    void build(int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<n){
                int v = max(0ll,a[lx]);
                tree[x][0]=tree[x][1]=tree[x][3]=v;
                tree[x][2]=a[lx];
            }
            return;
        }
        int mid = (lx+rx)>>1;
        build(2*x+1,lx,mid);
        build(2*x+2,mid,rx);
        tree[x] = merge(tree[2*x+1],tree[2*x+2]);
    }
    void update(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            int vv = max(0ll,v);
            tree[x][0]=tree[x][1]=tree[x][3]=vv;
            tree[x][2]=v;
            return;
        }
        int mid = (lx+rx)>>1;
        if(i<mid) update(i,v,2*x+1,lx,mid);
        else update(i,v,2*x+2,mid,rx);
        tree[x] = merge(tree[2*x+1],tree[2*x+2]);
    }
}st;
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m;cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    st.init();
    print(st.tree[0][3]);
    for (int i = 0; i < m; ++i)
    {
        int j,v;cin>>j>>v;
        st.update(j,v,0,0,st.sz);
        print(st.tree[0][3]);
    }
    return 0;
}
