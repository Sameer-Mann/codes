#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define print(a) cout<<a<<"\n";
#define test ll Testcases;cin>>Testcases;while(Testcases--)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll dp[30][30][30][2];
ll csb(ll n)
{
	ll c=0;
	while(n)
	{
		c++;
		n &= n-1;
	}
	return c;
}
ll f(ll ca,ll cb,ll i,ll cf,ll n,ll c)
{
	if(ca < 0 or cb < 0) return 0;
	if(i == n)
	{
		if(ca == 0 and cb == 0 and cf == 0) return 1;
		return 0;
	}
	if(dp[i][ca][cb][cf] != -1) return dp[i][ca][cb][cf];
	ll x = c&(1<<i);
	ll ans =0;
	if(x>0)
	{
		if(cf) ans = f(ca,cb,i+1,0,n,c)+f(ca-1,cb-1,i+1,1,n,c);
		else ans = f(ca-1,cb,i+1,0,n,c)+f(ca,cb-1,i+1,0,n,c);
	}
	else
	{
		if(cf) ans = f(ca-1,cb,i+1,1,n,c)+f(ca,cb-1,i+1,1,n,c);
		else ans = f(ca,cb,i+1,0,n,c)+f(ca-1,cb-1,i+1,1,n,c);
	}
	return dp[i][ca][cb][cf] = ans;
}
int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    test
    {
    	ll a,b,c;cin>>a>>b>>c;
    	ll ca=csb(a),cb=csb(b);
    	ll ds = c;
    	ll n=0;
    	while(ds)
    	{
    		n++;
    		ds >>=1;
    	}
    	memset(dp,-1,sizeof(dp));
    	print(f(ca,cb,0,0,n,c))
    }
	return 0;
}