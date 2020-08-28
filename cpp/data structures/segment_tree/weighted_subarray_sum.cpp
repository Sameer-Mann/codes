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
void print(T t){cout<< (t) ;cout<<'\n';}
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
struct item{
    int a,b;
};
item merge(item a,item b){
    return {a.a+b.a,a.b+b.b};
}
struct segtree{
    int sz;
    vector<item>tree;
    vector<int>ops;
    void init(int n,vector<int>&a){
        sz=1;
        while(sz<=n)sz<<=1;
        tree.assign(2*sz,{0,0});
        ops.assign(2*sz,0);
        build(a,0,0,sz);
    }
    void build(vector<int>&a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<a.size()){
                tree[x].a = (lx+1)*a[lx];
                tree[x].b = a[lx];
            }
            return;
        }
        int mid = (lx+rx)>>1;
        build(a,2*x+1,lx,mid);
        build(a,2*x+2,mid,rx);
        tree[x] = merge(tree[2*x+1],tree[2*x+2]);
    }
    void apply_op(item &a,int v,int l,int r){
        // if(v==no_op)return;
        a.a += v*((r*(r+1))/2 - (l*(l+1))/2);
        a.b += v*(r-l);
    }
    void apply_op1(int &a,int b){
        // if(b==no_op)return;
        a+=b;
    }
    void propagate(int x,int lx,int rx){
        if(rx-lx==1)return;
        int mid = (lx+rx)>>1;
        apply_op(tree[2*x+1],ops[x],lx,mid);
        apply_op(tree[2*x+2],ops[x],mid,rx);
        apply_op1(ops[2*x+1],ops[x]);
        apply_op1(ops[2*x+2],ops[x]);
        ops[x]=0;
        tree[x] = merge(tree[2*x+1],tree[2*x+2]);
    }
    void modify(int l,int r,int v,int x,int lx,int rx){
        propagate(x,lx,rx);
        if(rx<=l || lx>=r)return;
        if(lx>=l and rx<=r){
            apply_op(tree[x],v,lx,rx);
            apply_op1(ops[x], v);
            return;
        }
        int mid = (lx+rx)>>1;
        modify(l,r,v,2*x+1,lx,mid);
        modify(l,r,v,2*x+2,mid,rx);
        tree[x] = merge(tree[2*x+1],tree[2*x+2]);
    }
    void modify(int l,int r,int v){
        modify(l,r,v,0,0,sz);
    }
    item get(int l,int r,int x,int lx,int rx){
        propagate(x,lx,rx);
        if(lx>=r || rx<=l)return {0,0};
        if(lx>=l and rx<=r)return tree[x];
        int mid = (lx+rx)>>1;
        return merge(get(l,r,2*x+1,lx,mid),get(l,r,2*x+2,mid,rx));
    }
    item get(int l,int r){
        return get(l,r,0,0,sz);
    }
};
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fileio();
    int n,m;cin>>n>>m;
    vector<int>a(n);
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    segtree st;
    st.init(n,a);
    // print(st.tree[0].a,st.tree[0].b);
    for (int i = 0; i < m; ++i)
    {
        int t,l,r;cin>>t>>l>>r;
        if(t==1){
            int d;cin>>d;
            st.modify(l-1,r,d);
        }else{
            item ans = st.get(l-1,r);
            print(ans.a-(l-1)*ans.b);
        }
    }
    return 0;
}
