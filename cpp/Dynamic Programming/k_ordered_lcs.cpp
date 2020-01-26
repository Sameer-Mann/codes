#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define range(s,e,d,i) for (ll i =(s); i <=(e); i+=(d))
#define range2(s,e,d,i) for (ll i = s; i >= e; i -= d)
#define vll vector<ll>
#define print(a) cout<<a<<"\n";
#define input(a,n) range(0,n-1,1,i) cin>>a[i];
#define test ll Testcases;cin>>Testcases;while(Testcases--)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll f(ll i ,ll j,ll k ,vll &a,vll &b,vector<vector<vector<ll> > > &dp)
{
	if(i == a.size() || j == b.size())
	{
		return 0;
	}
	if(dp[i][j][k] != -1)
	{
		return dp[i][j][k];
	}
	ll ans = 0;
	if(a[i] == b[j])
	{
		ans = 1 + f(i+1,j+1,k,a,b,dp);
	}
	else
	{
		ans = max(f(i,j+1,k,a,b,dp),f(i+1,j,k,a,b,dp));
		if(k > 0)
		{
			ans = max(ans,1+f(i+1,j+1,k-1,a,b,dp));
		}
	}
	dp[i][j][k] = ans;
	return ans;
}
int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    fastIO
    ll n,m,k;cin>>n>>m>>k;
    vll a,b;
    a.resize(n,0);b.resize(m,0);
    input(a,n);
    input(b,m);
    vector<vector<vector<ll> > > dp;
    range(0,n,1,i)
    {
    	vector<vll>d;
    	range(0,m,1,j){
    		vll t;t.resize(k+1,-1);
    		d.pb(t);
    	}
    	dp.pb(d);
    }
    // range(0,n,1,i)
    // {
    // 	range(0,m,1,j){
    // 		range(0,k,1,x){
    // 			print(dp[i][j][x]);
    // 		}
    // 	}
    // }
    print(f(0,0,k,a,b,dp));
}