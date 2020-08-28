#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {return os << "(" << P.first << "," << P.second << ")";}
template<class T> ostream& operator<<(ostream &os, vector<T> V) {for(auto v : V) os << v << " ";return os<<"";}
template<class T> ostream& operator<<(ostream &os, set<T> S){os << "{ ";for(auto s:S) os<<s<<" ";return os<<"}";}
template<class T> ostream& operator<<(ostream &os, unordered_set<T> S){os << "{ ";for(auto s:S) os<<s<<" ";return os<<"}";}
template<class T> ostream& operator<<(ostream &os, multiset<T> S){os << "{ ";for(auto s:S) os<<s<<" ";return os<<"}";}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {os << "{ ";for(auto m:M) os<<"("<<m.fi<<":"<<m.se<<") ";return os<<"}";}
template<class L, class R> ostream& operator<<(ostream &os, unordered_map<L,R> M) {os << "{ ";for(auto m:M) os<<"("<<m.fi<<":"<<m.se<<") ";return os<<"}";}
template<typename T>
void print(T t){cout<< (t);cout<<'\n';}
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
    vector<int> tree;
    // in a range l to r r is always excluded
    void init(int n){
        size=1;
        while(size<n)size*=2;
        tree  = vector<int>(2*size,0);
    }
    void update(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
            tree[x] = v;
            return;
        }
        int m=(lx+rx)>>1;
        if(i<m) update(i,v,2*x+1,lx,m);
        else update(i,v,2*x+2,m,rx);
        tree[x] = tree[2*x+1]+tree[2*x+2];
    }
    void set(int i,int v){
        update(i,v,0,0,size);
    }
    int query(int l,int r,int x,int lx,int rx){
        if(lx>=r || rx<=l)return 0;
        if(lx>=l and rx<=r)return tree[x];
        int mid=(lx+rx)>>1;
        return query(l,r,2*x+1,lx,mid)+query(l,r,2*x+2,mid,rx);
    }
    int query(int l,int r){
        return query(l,r,0,0,size);
    }
};
int32_t main()
{
    fileio();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;cin>>n;
    vi a,vis;
    for (int i = 0; i < n; ++i)
    {
        int t;cin>>t;
        a.push_back(t);vis.push_back(0);
    }
    if(n==1){
        cout<<"0\n";
        return 0;
    }
    segtree st;
    st.init(n);
    st.set(a[0]-1,1);
    cout<<"0 ";
    for (int i = 1; i < n; ++i)
    {
        cout<<st.query(a[i],n)<<" ";
        st.set(a[i]-1,1);
    }
    cout<<endl;
    return 0;
}

