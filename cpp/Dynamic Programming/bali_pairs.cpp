#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
using namespace std;

ll dp[100000][100000];

ll f(ll l[],ll r[],ll i,ll sm,ll n)
{
	if(i == n)
	{
		if((sm%2) == 1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(dp[i][sm%mod] != -1)
	{
		return dp[i][sm%mod];
	}
	ll ans = (f(l,r,i+1,sm+l[i],n)%mod + f(l,r,i+1,sm+r[i],n)%mod)%mod;
	return dp[i][sm%mod] = ans;
}
int main()
{
	ll n;cin>>n;
	ll l[100000];
	ll r[100000];
	for(ll i = 0; i < n ;i++)
	{
		cin>>l[i]>>r[i];
	}
	ll m = 0;
	for(ll i = 0; i <n ; i++)
	{
		m += max(l[i],r[i]);
	}
	memset(dp,-1,sizeof(dp));
	cout<<f(l,r,0,0,n);
	return 0;
}