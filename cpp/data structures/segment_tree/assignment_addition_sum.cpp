#include <bits/stdc++.h>
#define int long long int
#define pi pair<int,int>
#define fi first
#define se second
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
struct segtree{
    int sz,no_op=-1;
    vector<int>tree;
    vector<pi>ops;
    void init(int n){
        sz=1;
        while(sz<=n)sz<<=1;
        tree.assign(2*sz,0);
        ops.assign(2*sz,make_pair(no_op,0));
    }
    void apply_op(int &a,pi b,int l){
        if(b.fi==no_op)return;
        if(b.fi==1) a = l*b.se;
        if(b.fi == 2) a += l*b.se;
    }
    void apply(pi &a,pi b){
        if(b.fi==no_op)return;
        if(b.fi==1)a = b;
        if(b.fi == 2){
            if(a.fi == no_op) a = b;
            else a.se+=b.se;
        }
    }
    void propagate(int x,int lx,int rx){
        if(rx-lx==1)return;
        int m = (lx+rx)>>1;
        apply_op(tree[2*x+1],ops[x],m-lx);
        apply_op(tree[2*x+2],ops[x],rx-m);
        apply(ops[2*x+1],ops[x]);
        apply(ops[2*x+2],ops[x]);
        ops[x] = make_pair(no_op,0);
        tree[x] = tree[2*x+1]+tree[2*x+2];
    }
    void modify(int l,int r,int v,int t,int x,int lx,int rx){
        propagate(x,lx,rx);
        if(lx>=r || rx<=l)return;
        if(lx>=l and rx<=r){
            apply_op(tree[x],make_pair(t,v),rx-lx);
            apply(ops[x],make_pair(t,v));
            return;
        }
        int mid =(lx+rx)>>1;
        modify(l,r,v,t,2*x+1,lx,mid);
        modify(l,r,v,t,2*x+2,mid,rx);
        tree[x] = tree[2*x+1]+tree[2*x+2];
    }
    void modify(int l,int r,int v,int t){
        modify(l,r,v,t,0,0,sz);
    }
    int get(int l,int r ,int x,int lx,int rx){
        propagate(x,lx,rx);
        if(lx>=r or rx<=l)return 0;
        if(lx>=l and rx<=r)return tree[x];
        int m = (lx+rx)>>1;
        return get(l,r,2*x+1,lx,m)+get(l,r,2*x+2,m,rx);
    }
    int get(int l,int r){
        return get(l,r,0,0,sz);
    }
};
int32_t main()
{
    fileio();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;cin>>n>>m;
    segtree st;
    st.init(n);
    for (int i = 0; i < m; ++i)
    {
        int t,l,r;cin>>t>>l>>r;
        if(t==1 || t==2){
            int v;cin>>v;
            st.modify(l,r,v,t);
        }else{
            print(st.get(l,r));
        }
    }
    return 0;
}
