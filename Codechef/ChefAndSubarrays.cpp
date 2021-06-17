#include "bits/stdc++.h"
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 1e5+2;
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int test;cin>>test;
    while(test--){
        int n,k;cin>>n>>k;
        vector<int>a(n+1);
        map<int,map<int,int>>d;
        for(int i = 1;i<=n;i++){
            cin>>a[i];
            d[i%k][a[i]]++;
        }
        int ans = 0;
        for(auto p:d){
            int mx = 0,tot=0;
            for(auto pp:p.se)mx=max(mx,pp.se),tot+=pp.se;
            ans += tot-mx;
        }
        print(ans);
    }
    return 0;
}