#include <bits/stdc++.h>
#define int long long int
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
int mod = 1e9+7;
void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
vector<vector<int>>g;
struct segtree{
    int sz,no_op=0;
    vector<int>tree;
    vector<int>ops;
    void init(int n){
        sz=1;
        while(sz<=n)sz<<=1;
        tree=vector<int>(2*sz,0);
        ops=vector<int>(2*sz,0);
    }
    void propagate(int x,int lx,int rx){
        if(rx-lx==1)return;
        int m = (lx+rx)>>1;
        tree[2*x+1] += ops[x]*(m-lx);
        tree[2*x+2] += ops[x]*(rx-m);
        ops[2*x+1] += ops[x];
        ops[2*x+2] += ops[x];
        ops[x] = 0;
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }
    void modify(int l,int r,int d,int x, int lx,int rx){
        propagate(x, lx, rx);
        if(rx<=l || lx>=r)return;
        if(lx>=l and rx<=r){
            tree[x] += d*(rx-lx);
            ops[x]+= d;
            return;
        }
        int mid =(lx+rx)>>1;
        modify(l,r,d,2*x+1,lx,mid);
        modify(l,r,d,2*x+2,mid,rx);
        tree[x] = tree[2*x+2]+tree[2*x+1];
    }
    void modify(int l,int r,int d){
        modify(l,r,d,0,0,sz);
    }
    void update(int i,int v,int x, int lx,int rx){
        propagate(x, lx, rx);
        if(rx-lx==1){
            tree[x]+=v;
            return;
        }
        int m = (lx+rx)>>1;
        if(i<m)update(i,v,2*x+1,lx,m);
        else update(i,v,2*x+2,m,rx);
        tree[x]=tree[2*x+1]+tree[2*x+2];
    }
    void set(int i,int v){
        update(i,v,0,0,sz);
    }
    int get(int l,int r,int x,int lx,int rx){
        propagate(x,lx,rx);
        if(lx>=r || rx<=l)return 0;
        if(lx>=l and rx<=r)return tree[x];
        int mid = (lx+rx)>>1;
        return get(l,r,2*x+1,lx,mid)+get(l,r,2*x+2,mid,rx);
    }
    int get(int l,int r){
        return get(l,r,0,0,sz);
    }
};
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fileio();
    int n,m;cin>>n>>m;
    segtree st;
    st.init(n);
    for (int i = 0; i < m; ++i)
    {
        int t;cin>>t;
        if(t==1){
            int l,r,a,d;cin>>l>>r>>a>>d;
            st.set(l-1,a);
            if(r==l){
                st.set(l,-a);
                continue;
            }
            st.set(r,-a);
            st.modify(l,r,d);
            st.set(r,(l-r)*d);
        }else{
            int x;cin>>x;
            print(st.get(0,x));
        }
    }
    // print(st.tree);
    return 0;
}
