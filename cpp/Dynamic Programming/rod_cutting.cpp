#include <iostream>
#include <climits>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[10000];
ll f(ll n,ll a[])
{
    if(n == 0){
        return 0;
    }
    if(n < 0){
        return -INT_MAX;
    }
    if(dp[n] != -1)
    {
        return dp[n];
    }
    ll ans = -INT_MAX;
    for(int i = 0; i < 3; i++)
    {
        if(n - a[i] >= 0)
        {
            ans = max(ans,1+f(n-a[i],a));
        }
    }
    return dp[n] = ans;
}
int main() {
    int t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        ll a[3];
        for(int i = 0 ; i < 3; i++)
        {
            cin>>a[i];
        }
        memset(dp,-1,sizeof(dp));
        cout<<f(n,a)<<endl;
    }
    //code
    return 0;
}