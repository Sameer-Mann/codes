#include "bits/stdc++.h"
#define int long long
using namespace std;
const int N = 1e5+2;
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {return os << "(" << P.first << "," << P.second << ")";}
#define print1(x) for(auto v:x){cout<<v<<' ';}
template<typename T>
void print(T t){cout<<(t);cout<<'\n';}
template<typename T, typename... Args>
void print(T t,Args... args){cout<<(t)<<' ';print(args...);}
vector<int>par;
vector<vector<int>>dp;
int logn,cycleId;
int climb(int node,int height){
    int j=0;
    while(height){
        if(height&1)node = dp[node][j];
        j++,height>>=1;
    }
    return node;
}
int getPar(int node,int turns){
    return climb(node,turns);
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int test;cin>>test;
    while(test--){
        int n;cin>>n;
        vector<int>a(n),p(n),vis(n,0);
        par = vector<int>(n);
        logn = log2l(n)+1,cycleId=0;
        dp = vector<vector<int>>(n,vector<int>(logn,0));
        for(int i =0;i<n;i++)cin>>a[i];
        for(int i =0;i<n;i++){
            cin>>p[i],p[i]--;
            par[p[i]] = i;
        }
        for(int i =0;i<n;i++){
            if(!vis[i]){
                int j=par[i];
                vector<int>a(1,i);
                while(j!=i){
                    vis[j]=1;
                    a.push_back(j);
                    j = par[j];
                }
                dp[a.back()][0] = a[0];
                for(int i =0;i<a.size()-1;i++){
                    dp[a[i]][0] = a[i+1];
                }
                for(int j=1;j<logn;j++){
                    for(int node:a){
                        dp[node][j] = dp[dp[node][j-1]][j-1];
                    }
                }
            }
        }
        int q,turns=0;cin>>q;
        while(q--){
            int tp;cin>>tp;
            if(tp==1){
                turns++;
            }else if(tp==2){
                int x,y;cin>>x>>y;
                x--,y--;
                int px=getPar(x,turns),py=getPar(y,turns);
                swap(a[px],a[py]);
            }else{
                int x;cin>>x;x--;
                int px = getPar(x,turns);
                print(a[px]);
            }
        }
    }
    return 0;
}