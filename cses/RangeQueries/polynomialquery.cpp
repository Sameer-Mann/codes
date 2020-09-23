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
vector<int>a;
int n,q;
struct segtree{
    vector<int>tree,ops,ops1;
    int sz;
    void init(){
        sz=1;
        while(sz<=n)sz<<=1;
        tree.assign(2*sz,0);
        ops.assign(2*sz,0);
        ops1.assign(2*sz,0);
        // build(0,0,sz);
    }
    void build(int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<n){
                print(x,lx);
                tree[x]=a[lx];
            }
            return;
        }
        int mid =(lx+rx)/2;
        build(2*x+1,lx,mid);
        build(2*x+2,mid,rx);
        tree[x]=tree[2*x+1]+tree[2*x+2];
    }
    void propagate(int x,int lx,int rx){
        if(rx-lx==1 or ops[x]==0)return;
        int mid = (lx+rx)/2;
        ops[2*x+1] += ops[x],ops[2*x+2] += ops[x];
        ops1[2*x+1] += ops1[x],ops1[2*x+2] += ops1[x];
        tree[2*x+1] += ops[x]*get(lx,mid)-ops1[x]*(mid-lx);
        tree[2*x+2] += ops[x]*get(mid,rx)-ops1[x]*(rx-mid);
        ops[x]=0,ops1[x]=0;
        tree[x]=tree[2*x+1]+tree[2*x+2];
    }
    int get(int l,int r){
        return r*(r+1)/2 - l*(l+1)/2;
    }
    void modify(int x,int lx,int rx,int l,int r){
        propagate(x,lx,rx);
        if(lx>=r or rx<=l)return;
        if(lx>=l and rx<=r){
            ops[x]++;
            ops1[x]+=l;
            tree[x] += get(lx,rx) - l*(rx-lx);
            return;
        }
        int mid =(lx+rx)/2;
        modify(2*x+1,lx,mid,l,r);
        modify(2*x+2,mid,rx,l,r);
        tree[x]=tree[2*x+1]+tree[2*x+2];
    }
    void modify(int l,int r){
        modify(0,0,sz,l,r);
    }
    int query(int x,int lx,int rx,int l,int r){
        propagate(x,lx,rx);
        if(lx>=r or rx<=l)return 0;
        if(lx>=l and rx<=r)return tree[x];
        int mid = (lx+rx)/2;
        return query(2*x+1,lx,mid,l,r)+query(2*x+2,mid,rx,l,r);
    }
    int query(int l,int r){
        return query(0,0,sz,l,r);
    }
};
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    a=vector<int>(n+1,0);
    for (int i = 1; i <= n; ++i) cin>>a[i],a[i]+=a[i-1];
    segtree st;
    st.init();
    for (int i = 0; i < q; ++i)
    {
        int t,l,r;cin>>t>>l>>r;
        l--;
        if(t==1){
            st.modify(l,r);
        }else{
            print(st.query(l,r)+a[r]-a[l]);
        }
    }
    return 0;
}