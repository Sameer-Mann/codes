#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll a[1000001];
ll dp[1000001];
ll f(ll i,ll n,ll a[])
{
	if(i == n)
	{
		return 0;
	}
	if(i > n)
	{
		return INT_MAX;
	}
	if(dp[i] != -1)
	{
		return dp[i];
	}
	ll ans = INT_MAX;
	for (int j = 1; j <= min(a[i],n-i); j++)
	{
	    if(a[i] == 0)
	    {
	        return INT_MAX;    
	    }
		ans = min(ans,1+f(i+j,n,a));
	}
	return dp[i] = ans;
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		ll n;cin>>n;
		ll a[n+1];
		memset(a,0,sizeof(a));
		for (ll i = 1; i <= n; ++i)
		{
			cin>>a[i];
		}
		memset(dp,-1,sizeof(dp));
		ll ans = f(1,n,a);
		if(ans >= INT_MAX){
		    cout<<-1<<endl;
		}else {
		    cout<<ans<<endl;
		}
	}
	return 0;
}