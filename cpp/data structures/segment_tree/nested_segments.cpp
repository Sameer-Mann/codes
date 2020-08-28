#include <bits/stdc++.h>
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
    vector<int>tree;
    int size;
    void init(int n){
        size = 1;
        while(size<n)size<<=1;
        tree = vector<int>(2*size,0);
    }
    void update(int i,int x,int lx,int rx){
        if(rx-lx==1){
            tree[x]=1;
            return;
        }
        int m=(lx+rx)/2;
        if(i<m)update(i,2*x+1,lx,m);
        else update(i,2*x+2,m,rx);
        tree[x]=tree[2*x+1]+tree[2*x+2];
    }
    void set(int i){
        update(i,0,0,size);
    }
    int query(int l,int r,int x,int lx,int rx){
        if(lx>=r || rx<=l)return 0;
        if(lx>=l and rx<=r)return tree[x];
        int m=(lx+rx)/2;
        return query(l,r,2*x+1,lx,m)+query(l,r,2*x+2,m,rx);
    }
    int q(int l,int r){
        return query(l,r+1,0,0,size);
    }
};
int32_t main()
{
    fileio();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;cin>>n;
    vector<int>ans(n,0);
    vector<vector<int>>a(n);
    segtree st;
    st.init(2*n);
    for (int i = 0; i < 2*n; ++i)
    {
        int t;cin>>t;
        a[t-1].push_back(i);
        if(a[t-1].size()==2){
            ans[t-1] = st.q(a[t-1][0],i);
            st.set(a[t-1][0]);
        }
    }
    print(ans);
    return 0;
}
