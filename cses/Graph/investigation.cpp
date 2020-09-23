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
#define graph vector<vii>
#define print(s) for(auto it:s) cout<<it<<" "
#define print2(s) for(auto it:s) cout<<it.fi<<" : "<<it.se
#define uset unordered_set
#define maxheap priority_queue<int>
#define minheap priority_queue<pii,vii,greater<pii>>
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
#define INF 1e18
graph g;
int n,m;
vi d,nodes,mx,mn,ct;
 
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    g=graph(n,vii(0));
    //cost.clear();
    for(int i=0;i<m;i++){
    int u,v,c;
    cin>>u>>v>>c;
    u--;v--;
    g[u].pb(mp(v,c));
 
    }
    d=vi(n,INF);
    nodes=vi(n,0);
    mx=vi(n,0);
    mn=vi(n,INF);
    ct=vi(n,0);
    minheap pq;
    pq.push(mp(0,0));
    d[0]=0;
    ct[0]=1;
    mx[0]=0,mn[0]=0;
    while(!pq.empty()){
        pii rmv=pq.top();
        pq.pop();
        if(rmv.fi!=d[rmv.se])continue;
        for(auto child:g[rmv.se]){
            if(d[child.fi]==d[rmv.se]+child.se){
                mx[child.fi]=max(mx[child.fi],mx[rmv.se]+1);
                mn[child.fi]=min(mn[child.fi],mn[rmv.se]+1);
                ct[child.fi]=(ct[child.fi]+ct[rmv.se])%MOD;
            }
            if(d[child.fi]>d[rmv.se]+child.se)
            {
                d[child.fi]=d[rmv.se]+child.se;
                mx[child.fi]=mx[rmv.se]+1;
                mn[child.fi]=mn[rmv.se]+1;
                ct[child.fi]=ct[rmv.se];
                pq.push(mp(d[child.fi],child.fi));
            }
        }
    }
    cout<<d[n-1]<<" "<<ct[n-1]<<" "<<mn[n-1]<<" "<<mx[n-1];
 
    return 0;
}