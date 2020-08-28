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
int n;
struct segtree
{
    vector<int>tree;
    int size;
    void init(int n){
        size = 1;
        while(size<n)size<<=1;
        tree = vector<int>(2*size,0);
        build(0,0,size);
    }
    void build(int x,int lx,int rx){
        if(rx-lx==1){
            if(lx<n){
                tree[x]=1;
            }
            return;
        }
        int m=(lx+rx)/2;
        build(2*x+1,lx,m);
        build(2*x+2,m,rx);
        tree[x]=tree[2*x+1]+tree[2*x+2];
    }
    void update(int i,int x,int lx,int rx){
        if(rx-lx==1){
            tree[x]=0;
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
    int query(int k,int x,int lx,int rx){
        if(rx-lx==1){
            return lx+1;
        }
        int m=(lx+rx)/2;
        if(tree[2*x+1]<k)return query(k-tree[2*x+1],2*x+2,m,rx);
        return query(k,2*x+1,lx,m);
    }
    int q(int k){
        return query(k,0,0,size);
    }
};
int32_t main()
{
    fileio();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    int a[n];
    for (int i = 0; i < n; ++i)cin>>a[i];
    int ans[n];
    segtree st;
    st.init(n);
    for(int i=n-1;i>=0;i--){
        ans[i]=st.q(i+1-a[i]);
        st.set(ans[i]-1);
    }
    for (int i = 0; i < n; ++i) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
