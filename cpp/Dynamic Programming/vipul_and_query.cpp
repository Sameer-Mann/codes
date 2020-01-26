#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define range(s,e,d,i) for (ll i =(s); i <=(e); i+=(d))
#define fst first
#define sd second
#define vll vector<ll>
#define umll unordered_map<string,ll>
#define print(a) cout<<a<<"\n";
#define test ll Testcases;cin>>Testcases;while(Testcases--)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<pair<ll,ll> >a;
ll n;
ll g(string s,char d)
{
	ll ct=0;
	range(0,s.length()-1,1,i)
	{
		if(s[i] == d) ct++;
	}
	return ct;
}
ll f(ll i,ll x,ll y,umll &dp)
{
	if(x<0 || y < 0) {
		return 0;
	}
	if(i == n) {
		return 0;
	}
	string st = to_string(i)+'+'+to_string(x)+'-'+to_string(y);
	if(dp.find(st) != dp.end()) {
		return dp[st];
	}
	ll ans = f(i+1,x,y,dp);
	if(x-a[i].fst >=0 && y-a[i].sd >=0){
		ans = max(ans,1+f(i+1,x-a[i].fst,y-a[i].sd,dp));
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
    a.clear();
    test
    {
    	string s;cin>>s;
    	a.pb(make_pair(g(s,'R'),g(s,'B')));
    }
    n = a.size();
    ll q;cin>>q;
    while(q--)
    {
    	ll x,y;cin>>x>>y;
    	umll dp;dp.clear();
    	print(f(0,x,y,dp));
    }
	return 0;
}