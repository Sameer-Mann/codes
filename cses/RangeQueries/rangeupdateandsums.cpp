#include <bits/stdc++.h>
#define int long long int
#define pii pair<int,int>
#define mp make_pair
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
int n,q;
vector<int>a;
struct segtree{
    vector<int>tree;
    // type,value
    vector<pii>ops;
    int sz;
    void init(){
        sz=1;
        while(sz<=n)sz<<=1;
        tree.assign(2*sz,0);
        // 1 for sum 
        // 2 for assignment
        ops.assign(2*sz,mp(-1,0));
        build(0,0,sz);
    }
    void build(int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<n)tree[x]=a[lx];
            return;
        }
        int mid = (lx+rx)/2;
        build(2*x+1,lx,mid);
        build(2*x+2,mid,rx);
        tree[x]=tree[2*x+1]+tree[2*x+2];
    }
    void propagate(int x,int lx,int rx){
        if(rx-lx == 1 or ops[x].fi == -1)return;
        int mid  =(lx+rx)/2;
        if(ops[x].fi == 2){
            ops[2*x+1] = ops[x];
            ops[2*x+2] = ops[x];
            tree[2*x+1] = (mid-lx)*ops[x].se;
            tree[2*x+2] = (rx-mid)*ops[x].se;
            tree[x]=tree[2*x+2]+tree[2*x+1];
            ops[x] = mp(-1,0);
            return;
        }
        if(ops[2*x+1].fi == -1)ops[2*x+1].fi = ops[x].fi;
        if(ops[2*x+2].fi == -1)ops[2*x+2].fi = ops[x].fi;
        ops[2*x+1].se += ops[x].se;
        ops[2*x+2].se += ops[x].se;
        tree[2*x+1] += ops[x].se*(mid-lx);
        tree[2*x+2] += ops[x].se*(rx-mid);
        ops[x] = mp(-1,0);
        tree[x]=tree[2*x+2]+tree[2*x+1];
    }
    void modify(int type,int val,int l,int r,int x,int lx,int rx){
        propagate(x,lx,rx);
        if(lx>=r or rx<=l)return;
        if(lx>=l and rx<=r){
            if(type == 1){
                tree[x] += val*(rx-lx);
                if(ops[x].fi == -1)ops[x].fi = type;
                ops[x].se += val;
            }else{
                tree[x] = val*(rx-lx);
                ops[x] = mp(type,val);
            }
            return;
        }
        int mid = (lx+rx)/2;
        modify(type,val,l,r,2*x+1,lx,mid);
        modify(type,val,l,r,2*x+2,mid,rx);
        tree[x]=tree[2*x+2]+tree[2*x+1];
    }
    void modify(int type,int l,int r,int val){
        modify(type,val,l,r,0,0,sz);
    }
    int get(int l,int r,int x,int lx,int rx){
        propagate(x,lx,rx);
        if(lx>=r or rx<=l)return 0;
        if(lx>=l and rx<=r)return tree[x];
        int mid =(lx+rx)/2;
        return get(l,r,2*x+1,lx,mid)+get(l,r,2*x+2,mid,rx);
    }
    int query(int l,int r){
        return get(l,r,0,0,sz);
    }
};
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    a=vector<int>(n);
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    segtree st;
    st.init();
    for (int i = 0; i < q; ++i)
    {
        int t,l,r;cin>>t>>l>>r;
        l--;
        if(t==1 || t==2){
            int val;cin>>val;
            st.modify(t,l,r,val);
        }else{
            print(st.query(l,r));
        }
    }
    return 0;
}