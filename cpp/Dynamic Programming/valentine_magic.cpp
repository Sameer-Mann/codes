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
ll f(ll i,ll j,vll &a,vll &b,vector<vll>&dp)
{
	if(i == a.size()){
		return 0;
	}
	if(j == b.size()){
		return INT_MAX;
	}
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	ll ans = 0;
	ans = min(abs(a[i]-b[j])+f(i+1,j+1,a,b,dp),f(i,j+1,a,b,dp));
	dp[i][j] = ans;
	return ans;
}
int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    fastIO
    ll n,m;cin>>n>>m;
    vll a,b;
    a.resize(n,0);b.resize(m,0);
    input(a,n);
    input(b,m);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<vll> dp;
    range(0,n,1,i)
    {
    	vll t;t.resize(m+1,-1);
    	dp.pb(t);
    }
    print(f(0,0,a,b,dp));
}