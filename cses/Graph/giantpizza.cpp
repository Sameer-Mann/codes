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
#define uset unordered_set
#define graph map<int,uset<int>>
#define print(s) for(auto it:s) cout<<it<<" "
#define print2(s) for(auto it:s) cout<<it.fi<<" : "<<it.se<<","
#define maxheap priority_queue<int>
#define minheap priority_queue<int,vi,greater<int>>
#define ln cout<<'\n'
#define space cout<<" "
#define len(x) x.size()
#define bits(x) _builtin_popcount(x)
graph g,gr;
int n,m,scc=0,timer=0;
map<int,int> assignment,comp;
vi topo;
uset<int>seen;
int getNode(int x){
if(x>0){
return 2*x;
}
return 2*(-x)+1;
}
void dfs1(int u){
seen.insert(u);
for(auto child:g[u]){
if(!seen.count(child))dfs1(child);
}
topo.pb(u);
}
void dfs2(int u){
seen.insert(u);
comp[u]=scc;
for(auto child:gr[u]){
if(!seen.count(child))dfs2(child);
}
}
bool solve2Sat(){
for(int i=1;i<=m;i++){
if(!g.count(getNode(i)) and !gr.count(getNode(i))){continue;}
if(comp[getNode(i)]==comp[getNode(-i)])return 0;
assignment[i]=comp[getNode(i)]>comp[getNode(-i)];
}
return 1;
}
// + + + + - + - - - + 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    g.clear();
    gr.clear();
    seen.clear();
    comp.clear();
    assignment.clear();
    for(int i=0;i<n;i++){
    int a,b;
    char p,q;
    cin>>p>>a>>q>>b;
    if(p=='-')a=-a;
    if(q=='-')b=-b;
    g[getNode(-a)].insert(getNode(b));
    g[getNode(-b)].insert(getNode(a));
    gr[getNode(b)].insert(getNode(-a));
    gr[getNode(a)].insert(getNode(-b));
    }

    for(auto &root:g){
    if(!seen.count(root.fi)){dfs1(root.fi);}
    }
    reverse(topo.begin(), topo.end());
    seen.clear();
    for(auto i:topo){
    if(!seen.count(i)){dfs2(i);scc++;}
    }
    bool f=solve2Sat();
    if(!f)cout<<"IMPOSSIBLE";
    else{
    for(int i=1;i<=m;i++){
    if(assignment[i])cout<<"+ ";
    else cout<<"- ";
    }
    }
    return 0;
}