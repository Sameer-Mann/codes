#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define range(s,e,d,i) for (ll i =(s); i <=(e); i+=(d))
#define vll vector<ll>
#define umll unordered_map<ll,ll>
#define print(a) cout<<a<<"\n";
#define input(a,n) range(0,n-1,1,i) cin>>a[i];
#define test ll Testcases;cin>>Testcases;while(Testcases--)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll f(ll st,ll end,vll &a,vll &b,vector<vll>&dp,umll &d)
{
	if(st >= end)
	{
		return 0;
	}
	if(dp[st][end] != -1)
	{
		return dp[st][end];
	}
	ll sm = b[end]-b[st]+a[st];
	if(sm%2 != 0){
		return 0;
	}
	sm = (int)(sm/2) + b[st]-a[st];
	if(d.find(sm) == d.end()){
		return 0;
	}
	ll idx = d[sm];
	ll ans = 1 + max(f(st,idx,a,b,dp,d),f(idx+1,end,a,b,dp,d));
    return dp[st][end] = ans;
}
int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    fastIO
    test
    {
    	ll n;cin>>n;
    	vll a;a.resize(n,0);
    	input(a,n);
    	vll b;b.resize(n,0);
        b[0] = a[0];
        umll d;
        d[a[0]] = 0;
    	range(1,n-1,1,i)
    	{
            b[i] = b[i-1]+a[i];
            d[b[i]] = i;
    	}
    	vector<vector<ll> > dp;
    	range(0,n-1,1,i)
    	{
    		vll t;t.resize(n,-1);
    		dp.pb(t);
    	}
    	print(f(0,n-1,a,b,dp,d));
    }
    return 0;
}