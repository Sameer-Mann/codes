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
    int size;
    vector<int> tree;
    int no_op = INT_MAX;
    void init(int n){
        size=1;
        while(size<n)size*=2;
        tree = vector<int>(2*size,0);
    }
    void apply_op(int &a,int b){
        if(b==no_op)return;
        a=b;
    }
    void propagate(int x,int lx,int rx){
        if(rx-lx==1)return;
        apply_op(tree[2*x+1],tree[x]);
        apply_op(tree[2*x+2],tree[x]);
        tree[x]=no_op;
    }
    void modify(int l,int r,int v,int x,int lx,int rx){
        propagate(x,lx,rx);
        if(lx>=r || rx<=l)return;
        if((lx>=l and rx<=r) ||(rx-lx==1)){
            apply_op(tree[x],v);
            return;
        }
        int m=(lx+rx)>>1;
        modify(l,r,v,2*x+1,lx,m);
        modify(l,r,v,2*x+2,m,rx);
    }
    void modify(int l,int r,int v){
        modify(l,r,v,0,0,size);
    }
    int query(int i,int x,int lx,int rx){
        propagate(x,lx,rx);
        if(rx-lx==1) return tree[x];
        int m = (lx+rx)>>1;
        if(i<m)return query(i,2*x+1,lx,m);
        return query(i,2*x+2,m,rx);
    }
    int query(int i){
        return query(i,0,0,size);
    }
};
int32_t main()
{
    fileio();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;cin>>n>>m;
    segtree st;
    st.init(n);
    // print(st.tree);
    for (int i = 0; i < m; ++i)
    {
        int t;cin>>t;
        if(t==1){
            int l,r,v;cin>>l>>r>>v;
            st.modify(l,r,v);

        }else{
            int x;cin>>x;
            print(st.query(x));
        }
    }
    // print(st.tree);
    return 0;
}
