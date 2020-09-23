#include <iostream>
#include <vector>
#include <cstring>
#define mod 1000000007
using namespace std;
int x,n,m;
vector<vector<int>>g;
int best[21];
int dp[21][1050000];
int f(int u,int mask){
    if(mask == x)return best[u];
    if(dp[u][mask]!=-1)return dp[u][mask];
    int ans = 0;
    for(auto nbr:g[u]){
        if((mask&(1<<nbr)) == 0){
            ans = (ans + f(nbr,mask|(1<<nbr)))%mod;
        }
    }
    return dp[u][mask]=ans%mod;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    g = vector<vector<int>>(n);
    memset(dp,-1,sizeof(dp));
    memset(best,0,sizeof(best));
    x = (1<<(n-1)) - 1;
    for (int i = 0; i < m; ++i)
    {
        int u,v;cin>>u>>v;
        u--,v--;
        if(v==n-1){
            best[u]++;
            continue;
        }
        g[u].push_back(v);
    }
    cout<<f(0,1)<<endl;
    return 0;
}

// Design and Simulation of Op-Amp based Comparator for Sigma
// Delta Modulator