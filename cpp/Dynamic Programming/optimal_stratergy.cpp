#include <iostream>
#define ll long long
using namespace std;
ll dp[100][100];
ll f(bool turn,int i,int j,ll a[])
{
	if(i == j)
	{
		return 0;
	}
	if(dp[i][j] != -1)
	{
		return dp[i][j];
	}
	ll ans = 0;
	if(turn)
	{
		ans = max(a[i] + f(false,i+1,j,a),a[j] + f(false,i,j-1,a));
	}
	else
	{
		ans = max(f(true,i,j-1,a),f(true,i+1,j,a));
	}
	return dp[i][j] = ans;
}
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		ll a[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
		memset(dp,-1,sizeof(dp));
		cout<<f(true,0,n-1,a)<<endl;
	}
	return 0;
}