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
struct node{
    vector<int>a;
    node(){
        a.clear();
    }
};
int n,q;
struct segtree
{
    int size;
    vector<node> tree;
    // in a range l to r r is always excluded
    void init(int n){
        size=1;
        while(size<n)size*=2;
        tree  = vector<node>(2*size);
    }
    node merge(node &a,node &b){
        node c;
        int i=0,j=0;
        while(true){
            int mn=LLONG_MAX;
            if(i<a.a.size()){
                mn=min(mn,a.a[i]);
            }
            if (j<b.a.size()){
                mn =min(mn,b.a[j]);
            }
            if(mn == LLONG_MAX)break;
            if(i<a.a.size() and mn==a.a[i]){
                c.a.push_back(mn);
                i++;
            }else{
                c.a.push_back(mn);
                j++;
            }
        }
        return c;
    }
    void build(vector<int> &a,int x ,int lx, int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()){
                tree[x].a.push_back(a[lx]);
            }
            return;
        }
        int m = (lx+rx)>>1;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        tree[x]=merge(tree[2*x+1],tree[2*x+2]);
    }
    void build(vector<int>&a){
        build(a,0,0,size);
    }
    int get(node &arr,int x){
        int xx = 0;
        if( arr.a.size() and x<arr.a[0]){
            xx = arr.a.size();
        }else{
            xx = arr.a.size() - (upper_bound(arr.a.begin(),arr.a.end(),x)-arr.a.begin());
        }
        return xx;
    }
    int query(int l,int r,int x,int lx,int rx){
        if(lx>=r || rx<=l)return 0;
        if(lx>=l and rx<=r)return get(tree[x],r);
        int m = (lx+rx)>>1;
        return query(l,r,2*x+1,lx,m)+query(l,r,2*x+2,m,rx);
    }
    int query(int l,int r){
        return query(l,r,0,0,size);
    }
};
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    map<int,set<int>>d;
    vector<int>a(n),b;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        d[a[i]].insert(i+1);
    }
    for (int i = 0; i < n; ++i)
    {
        auto idx = d[a[i]].upper_bound(i+1);
        if(idx == d[a[i]].end()){
            b.push_back(INT_MAX);
        }else b.push_back(*idx);
    }
    segtree st;
    st.init(n);
    st.build(b);
    for (int i = 0; i < q; ++i)
    {
        int l,r;cin>>l>>r;
        print(st.query(l-1,r));
    }
    return 0;
}
