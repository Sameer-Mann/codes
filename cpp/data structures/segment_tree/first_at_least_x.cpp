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
vector<int>a,tree;
int n,sz;
void build(int x,int lx,int rx){
    if(rx-lx==1){
        if(lx<n)tree[x]=a[lx];
        return;
    }
    int mid = (lx+rx)>>1;
    build(2*x+1,lx,mid);
    build(2*x+2,mid,rx);
    tree[x] = tree[2*x+1]>tree[2*x+2]?tree[2*x+1]:tree[2*x+2];
}
void update(int i,int v,int x,int lx,int rx){
    if(rx-lx==1){
        tree[x] = v;
        return;
    }
    int mid = (lx+rx)>>1;
    if(i<mid)update(i,v,2*x+1,lx,mid);
    else update(i,v,2*x+2,mid,rx);
    tree[x] = tree[2*x+1]>tree[2*x+2]?tree[2*x+1]:tree[2*x+2];
}
int get(int k,int x,int lx,int rx){
    if(tree[x]<k)return -1;
    if(rx-lx==1)return lx;
    int mid = (lx+rx)/2;
    int ans = get(k,2*x+1,lx,mid);
    if(ans==-1)ans = get(k,2*x+2,mid,rx);
    return ans;
}
void init(){
    sz=1;
    while(sz<=n)sz<<=1;
    tree.assign(2*sz,INT_MIN);
    build(0,0,sz);
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m;cin>>n>>m;
    a.assign(n,0);
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    init();
    for (int i = 0; i < m; ++i)
    {
        int t,k;cin>>t>>k;
        if(t==1){
            int v;cin>>v;
            update(k,v,0,0,sz);
        }
        else print(get(k,0,0,sz));
    }
    return 0;
}
