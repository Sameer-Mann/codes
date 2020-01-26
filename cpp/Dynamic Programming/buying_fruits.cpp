#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define range(s,e,d,i) for (ll i =(s); i <= (e); i+=(d))
#define vll vector<ll>
#define print(a) cout<<a<<"\n";
#define umll unordered_map<string ,ll>
#define input(a,n) range(0,n-1,1,i) cin>>a[i];
#define test ll Testcases;cin>>Testcases;while(Testcases--)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll f(ll i, ll n,ll id,umll &dp,vector<vector<ll> >&fruits)
{
	if(i == n){
		return 0;
	}
	string st = to_string(i)+" "+to_string(id);
	if(dp.find(st) != dp.end()) return dp[st];
	ll ans = 0;
	if(id == 1)
	{
		ans = min(fruits[i][1]+f(i+1,n,2,dp,fruits),fruits[i][2]+f(i+1,n,3,dp,fruits));
	}
	else if (id == 2)
	{
		ans = min(fruits[i][0]+f(i+1,n,1,dp,fruits),fruits[i][2]+f(i+1,n,3,dp,fruits));
	}
	else
	{
		ans = min(fruits[i][1]+f(i+1,n,2,dp,fruits),fruits[i][0]+f(i+1,n,1,dp,fruits));
	}
	return dp[st] = ans;
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
    	vector<vector<ll> >fruits;
    	ll t = n;
    	while(t--)
    	{
    		vll temp;
    		range(1,3,1,i){
    			ll c;cin>>c;
    			temp.pb(c);
    		}
    		fruits.pb(temp);
    	}
    	umll dp;ll ans1 =f(0,n,1,dp,fruits);dp.clear();
    	ll ans2 =f(0,n,2,dp,fruits);dp.clear();
    	ll ans3 =f(0,n,3,dp,fruits);
    	print(min(ans1,min(ans2,ans3)))
    }
	return 0;
}