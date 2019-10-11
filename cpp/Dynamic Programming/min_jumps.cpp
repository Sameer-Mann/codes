#include <iostream>
#define ll long long 
using namespace std;
ll a[10000001];
ll dp[10000001];
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
		for (ll i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
		memset(dp,-1,sizeof(dp));
		cout<<f(1,n,a)<<endl;
	}
	return 0;
}