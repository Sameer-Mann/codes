#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define range(s,e,d,i) for (ll i =(s); i <= (e); i+=(d))
#define fst first
#define sd second
#define vll vector<ll>
#define print(a) cout<<a<<"\n";
#define input(a,n) range(0,n-1,1,i) cin>>a[i];
#define test ll Testcases;cin>>Testcases;while(Testcases--)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll mod = 1000000007;
ll f(string s,ll a[],ll i,ll dp[],ll n)
{
	if(i == n) return 0;
	if(dp[i] != -1) return dp[i];
	ll maxl = INT_MAX;
	ll ans = 0;
	range(i,n-1,1,j)
	{
		ll code = a[(ll)(s[j]-'a')];
		maxl = min(maxl,code);
		ll lsf = j-i;
		if(lsf + 1 <= maxl)
		{
			ans = max(1+f(s,a,j+1,dp,n),ans);
		}
	}
	// ans %= mod;
	return dp[i] = ans;
}
int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    ll n;cin>>n;
    string s;cin>>s;
    ll a[26];input(a,26);
    ll dp[n];
    memset(dp,-1,sizeof(dp));
    print(f(s,a,0,dp,n));
	return 0;
}