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
struct segtree {
    int sz;
    vector<int>tree;
    void init(vector<int>&a){
        sz=1;
        while(sz<=a.size())sz<<=1;
        tree.assign(2*sz,0);
        build(a,0,0,sz);
    }
    void build(vector<int>&a,int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<a.size())tree[x]=a[lx];
            return;
        }
        int mid = (lx+rx)>>1;
        build(a,2*x+1,lx,mid);
        build(a,2*x+2,mid,rx);
        tree[x] = tree[2*x+1]+tree[2*x+2];
    }
    void update(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            tree[x] = v;
            return;
        }
        int mid = (lx+rx)>>1;
        if(i<mid)update(i,v,2*x+1,lx,mid);
        else update(i,v,2*x+2,mid,rx);
        tree[x] = tree[2*x+1]+tree[2*x+2];
    }
    int get(int l,int r,int x,int lx,int rx){
        if(lx>=r or rx<=l)return 0;
        if(lx>=l and rx<=r)return tree[x];
        int mid=  (lx+rx)>>1;
        return get(l,r,2*x+1,lx,mid)+get(l,r,2*x+2,mid,rx);
    }

}st;
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;cin>>n>>m;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    st.init(a);
    for (int  i = 0; i < m; i++)
    {
        int t,l,r;cin>>t>>l>>r;
        if(t==1){
            st.update(l,r,0,0,st.sz);
        }else{
            print(st.get(l,r,0,0,st.sz));
        }
    }
    return 0;
}
