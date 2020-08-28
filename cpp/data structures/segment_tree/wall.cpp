#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
#define int long long int
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define graph vector<vector<int>>
#define print(s) for(auto it:s) cout<<it<<" "
#define print2(s) for(auto it:s) cout<<it.fi<<" : "<<it.se
#define uset unordered_set
#define maxheap priority_queue<int>
#define minheap priority_queue<int,vi,greater<int>>
#define ln cout<<'\n'
#define space cout<<" "
#define len(x) x.size()
#define bits(x) _builtin_popcount(x)
graph g;
struct item{
    int max;
    int min;
};
item No_op={INT_MAX,0};
item apply_op(item t1,item t2){
    t1.max= min(t1.max,t2.max);
    t1.max=max(t1.max,t2.min);
    t1.min= max(t1.min,t2.min);
    t1.min=min(t1.min,t2.max);
    return t1;
}
struct segtree{
    vector<item>operations;
    int size;
    void init(int n){
        size=1;
        while(size<=n)size*=2;
        operations=vector<item>(2*size,{INT_MAX,0});
    }
    void propagate(int x,int lx,int rx){
        if(rx-lx==1)return;
        operations[2*x+1]=apply_op(operations[2*x+1],operations[x]);
        operations[2*x+2]=apply_op(operations[2*x+2],operations[x]);
        operations[x]=No_op;
       
    }
    void add(int l,int r,int h ,int x,int lx,int rx){
        propagate(x,lx,rx);
        if(rx<=l or lx>=r)return;
        if(lx>=l and rx<=r){
            operations[x]=apply_op(operations[x],{INT_MAX,h});
            return;
        }
        int m=(lx+rx)/2;
        add(l,r,h,2*x+1,lx,m);
        add(l,r,h,2*x+2,m,rx);
    }
    void add(int l,int r,int h){
        add(l,r,h,0,0,size);
    }
    void remove(int l,int r,int h,int x,int lx,int rx){
        propagate(x,lx,rx);
        if(rx<=l or lx>=r)return;
        if(lx>=l and rx<=r){
            operations[x]=apply_op(operations[x],{h,INT_MIN});
            return;
        }
        int m=(lx+rx)/2;
        remove(l,r,h,2*x+1,lx,m);
        remove(l,r,h,2*x+2,m,rx);
    }
    void remove(int l,int r,int h){
        remove(l,r,h,0,0,size);
    }
    int get(int i,int x,int lx,int rx){
        propagate(x,lx,rx);
        if(rx-lx==1){
            return min(operations[x].min,operations[x].max);
        }
        int m=(lx+rx)/2;
        if(i<m){
            return get(i,2*x+1,lx,m);
        }
        return get(i,2*x+2,m,rx);
    }
    int get(int i){
        return get(i,0,0,size);
    }
};
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    #endif
    int n,k;
    cin>>n>>k;
    segtree s;
    s.init(n);
    for(int i=0;i<k;i++){
        int op,l,r,h;
        cin>>op>>l>>r>>h;
        if(op==1){
            s.add(l,r+1,h);
        }else{
            s.remove(l,r+1,h);
        }
   
    }
    for(int j=0;j<n;j++){
        cout<<s.get(j);ln;
    }
    return 0;
}
