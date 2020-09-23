//start of cp 2.0 
//DEAD PERSON CODING
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
void fileio()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
struct node{
vector<node*>versions;
int sum;
node* l;
node* r;
node(){}
node(int val,node* left,node* right){
l=left;
r=right;
sum=val;
if(l)sum+=l->sum;
if(r)sum+=r->sum;
}

};
vector<node*>versions;
vi a;
map<int,node*>mapping;
void build(node* root,int lx,int rx){
if(rx-lx==1){
if(lx<a.size())
root->sum=a[lx];
return;
}
int m=(lx+rx)/2;
node* l=new node(0,NULL,NULL);
node* r=new node(0,NULL,NULL);
build(l,lx,m);
build(r,m,rx);
root->sum=l->sum+r->sum;
root->l=l;
root->r=r;

}
int query(node* root,int lx,int rx,int l,int r){
if(rx<=l or r<=lx)return 0;
if(lx>=l and rx<=r)return root->sum;
int m=(lx+rx)/2;
return query(root->l,lx,m,l,r)+query(root->r,m,rx,l,r);
}
void upgrade(node* original , node* copy ,int lx ,int rx,int idx,int val){
if(idx>=rx or idx<lx or lx>=rx)return;
if (rx-lx==1){ 
copy->sum = val; 
        return; 
    } 
    int m = (lx+rx)/2; 
    if (idx < m) 
    { copy->r = original->r; 
        copy->l = new node((int)0,NULL, NULL); 
        upgrade(original->l,copy->l, lx, m, idx, val); 
    } 
    else
    { 
        copy->l = original->l; 
        copy->r = new node((int)0,NULL, NULL); 
        upgrade(original->r, copy->r, m, rx, idx, val); 
    }
    copy->sum = copy->l->sum + copy->r->sum; 
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fileio();
    int n,q;
    cin>>n>>q;
    a=vi(n,0);
    node* root=new node(0,NULL,NULL);
    for(int i=0;i<n;i++)cin>>a[i];
    build(root,0,n);
mapping[1]=root;
int ct=2;
while(q-->0){
int t,k;
cin>>t>>k;
if(t==3){
mapping[ct]=mapping[k];
ct++;
}else if(t==2){
int l,r;
cin>>l>>r;
l--;
cout<<query(mapping[k],0,n,l,r);ln;

}else{
int idx,val;
cin>>idx>>val;
idx--;
node* temp=new node(0,NULL,NULL);
upgrade(mapping[k],temp,0,n,idx,val);
mapping[k]=temp;


}
}
    return 0;
}