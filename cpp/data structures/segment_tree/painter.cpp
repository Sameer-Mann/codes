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
    int pcolor,suffcolor,seg,ct;
};
int no_color=-1;
item merge(item a,item b){
    item c = {a.pcolor,b.suffcolor,a.seg+b.seg,a.ct+b.ct};
    if(a.suffcolor == b.pcolor and b.pcolor == 1){
        c.seg--;
    }
    return c;
}
void apply_op(item &a,int color ,int l){
    if(color == no_color)return;
    a.pcolor = a.suffcolor = color;
    a.seg = color==1;
    a.ct = l*(color==1);

}
void apply_op1(int &a,int color){
    if(color == no_color)return;
    a = color;
}
struct segtree{
    int sz;
    vector<item>tree;
    vector<int>ops;
    void init(int n){
        sz=1;
        while(sz<=n)sz<<=1;
        tree.assign(2*sz,{0,0,0,0});
        ops.assign(2*sz, no_color);
    }
    void propagate(int x,int lx,int rx){
        if(rx-lx==1)return;
        int m=(lx+rx)>>1;
        apply_op(tree[2*x+1], ops[x],m-lx);
        apply_op(tree[2*x+2], ops[x],rx-m);
        apply_op1(ops[2*x+1], ops[x]);
        apply_op1(ops[2*x+2], ops[x]);
        ops[x] = no_color;
        tree[x] = merge(tree[2*x+1],tree[2*x+2]);
    }
    void modify(int l,int r,int color,int x,int lx,int rx){
        propagate(x, lx, rx);
        if(lx>=r || rx<=l)return;
        if(lx>=l and rx<=r){
            apply_op(tree[x], color,rx-lx);
            apply_op1(ops[x], color);
            return;
        }
        int mid = (lx+rx)>>1;
        modify(l,r,color,2*x+1,lx,mid);
        modify(l,r,color,2*x+2,mid,rx);
        tree[x] = merge(tree[2*x+1],tree[2*x+2]);
    }
    void modify(int l,int r,int color){
        modify(l,r,color,0,0,sz);
    }
};
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fileio();
    int n;cin>>n;
    segtree st;
    st.init(1e6+1e2);
    int ch = 5e5+1;
    for (int i = 0; i < n; ++i)
    {
        char t;
        int x,l;cin>>t>>x>>l;
        x+=ch;
        st.modify(x-1,x+l-1,(t=='B'));
        print(st.tree[0].seg,st.tree[0].ct);
    }
    return 0;
}
