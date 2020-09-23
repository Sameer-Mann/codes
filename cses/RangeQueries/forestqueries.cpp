#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define N 1024
int n,q;
vi path;
struct segtree{
    vi values;
    int size;
    void init(int n){
        size=1;
        while(size<=n)size*=2;
        values=vi(2*size,0);
    }
    void set(int x,int lx,int rx,int i){
        path.pb(x);
        if(rx-lx==1){values[x]^=1;return;}
        int m=(lx+rx)/2;
        if(i<m)set(2*x+1,lx,m,i);
        else set(2*x+2,m,rx,i);
        values[x]=values[2*x+1]+values[2*x+2];
    }
    void set(int i){
        path.clear();
        set(0,0,size,i);
        reverse(path.begin(), path.end());
    }
    void build(int x,int lx,int rx,vi &a){
        if(rx-lx==1){
            if(lx<a.size())values[x]=a[lx];
            return;
        }
        int mid = (lx+rx)/2;
        build(2*x+1,lx,mid,a);
        build(2*x+2,mid,rx,a);
        values[x]=values[2*x+1]+values[2*x+2];
    }
    void build(vi &a){
        build(0,0,size,a);
    }
    int calc(int x,int lx,int rx,int l,int r){
        if(rx<=l or r<=lx)return 0;
        if(lx>=l and rx<=r)return values[x];
        int m=(lx+rx)/2;
        return calc(2*x+1,lx,m,l,r)+calc(2*x+2,m,rx,l,r);
    }
    int calc(int l,int r){
        return calc(0,0,size,l,r);
    }
};
struct segtree_2D{
    vector<segtree>values;
    int size;
    void init(int n){
        size=1;
        while(size<=n)size*=2;
        segtree  s;
        s.init(n);
        values=vector<segtree>(2*size,s);
    }
 
    void merge(int x,int lx,int rx){
        if(rx-lx==1)return;
        for(int i=0;i<values[x].values.size();i++){
            values[x].values[i]=values[2*x+1].values[i]+values[2*x+2].values[i];
        }
    }
    void build(int x,int lx,int rx,vector<segtree>&a){
        if(rx-lx==1){
            if(lx<a.size())values[x]=a[lx];
            return;
        }
        int m=(lx+rx)/2;
        build(2*x+1,lx,m,a);
        build(2*x+2,m,rx,a);
        merge(x,lx,rx);
    }
    void build(vector<segtree>&a){
        build(0,0,size,a);
    }
    void merge_modify(int x){
        for(auto i:path){
            values[x].values[i]=values[2*x+1].values[i]+values[2*x+2].values[i];
        }
    }
    int calc(int x,int lx,int rx,int y1,int y2,int x1,int x2){
        if(lx>=y2 or rx<=y1) return 0;
        if(lx>=y1 and rx<=y2)return values[x].calc(x1,x2);
        int m=(lx+rx)/2;
        return calc(2*x+1,lx,m,y1,y2,x1,x2)+calc(2*x+2,m,rx,y1,y2,x1,x2);
    }
    int calc(int y1,int y2,int x1,int x2){
        return calc(0,0,size,y1,y2,x1,x2);
    }
    void modify(int x,int lx,int rx,int y,int xc){
        if(rx-lx==1){values[x].set(xc);return;}
        int m=(lx+rx)/2;
        if(y<m)modify(2*x+1,lx,m,y,xc);
        else modify(2*x+2,m,rx,y,xc);
        merge_modify(x);
    }
    void modify(int y,int xc){
        modify(0,0,size,y,xc);
    }
};
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin>>n>>q;
    vector<segtree>a;
    for(int i=0;i<n;i++){
        segtree s;
        s.init(n);
        vi b;
        for(int j=0;j<n;j++){
            char ch;
            cin>>ch;
            b.pb(ch=='*');
        }
        s.build(b);
        a.pb(s);
    }
    segtree_2D tree;
    tree.init(n);
    tree.build(a);
 
    for(int i=0;i<q;i++){
        int t;
        cin>>t;
        if(t==1){
            int y,x;
            cin>>y>>x;
            y--;x--;
            tree.modify(y,x);
        }else{
            int y1,x1,y2,x2;
            cin>>y1>>x1>>y2>>x2;
            y1--;x1--;y2--;x2--;
            cout<<tree.calc(y1,y2+1,x1,x2+1)<<'\n';
        }
    }
    return 0;
}