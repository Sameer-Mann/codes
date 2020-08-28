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
void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
int mod = 1e9+7;
struct segtree
{
    int size;
    vector<int> tree;
    vector<int> operations;
    int no_op=LLONG_MAX-1,neutral=0;
    void init(int n){
        size=1;
        while(size<n)size*=2;
        tree = vector<int>(2*size,0ll);
        operations = vector<int>(2*size,0ll);
    }
    void apply_op1(int &a,int b,int len){
        if(b==no_op)return;
        a= 1ll*len*b;
    }
    void apply_op(int &a,int b){
        if(b==no_op)return;
        a=b;
    }
    int merge(int a,int b){
        return a+b;
    }
    void propagate(int x,int lx,int rx){
        if(rx-lx==1)return;
        int m=(lx+rx)>>1;
        apply_op1(tree[2*x+1],operations[x],m-lx);
        apply_op1(tree[2*x+2],operations[x],rx-m);
        apply_op(operations[2*x+1],operations[x]);
        apply_op(operations[2*x+2],operations[x]);
        operations[x]=no_op;
    }
    void modify(int l,int r,int v,int x,int lx,int rx){
        propagate(x,lx,rx);
        if(lx>=r || rx<=l)return;
        if((lx>=l and rx<=r)){
            apply_op(operations[x],v);
            apply_op1(tree[x],v,rx-lx);
            return;
        }
        int m=(lx+rx)>>1;
        modify(l,r,v,2*x+1,lx,m);
        modify(l,r,v,2*x+2,m,rx);
        tree[x]=merge(tree[2*x+1],tree[2*x+2]);
        apply_op1(tree[x],operations[x],rx-lx);
    }
    void modify(int l,int r,int v){
        modify(l,r,v,0,0,size);
    }
    int query(int l,int r,int x,int lx,int rx){
        propagate(x,lx,rx);
        if(lx>=r||rx<=l)return neutral;
        if(lx>=l and rx<=r)return tree[x];
        int m = (lx+rx)>>1;
        int ans = merge(query(l,r,2*x+1,lx,m),query(l,r,2*x+2,m,rx));
        return ans;
    }
    int query(int l,int r){
        return query(l,r,0,0,size);
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
        if(t==1){
            int v;cin>>v;
            st.modify(l,r,v);

        }else{
            print(st.query(l,r));
        }
    }
    // print(st.tree);
    // print(st.operations);
    return 0;
}
