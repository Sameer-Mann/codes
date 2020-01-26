#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define range(s,e,d,i) for (ll i =(s); i <=(e); i+=(d))
#define vll vector<ll>
#define print(a) cout<<a<<"\n";
#define input(a,n) range(0,n-1,1,i) cin>>a[i];
#define test ll Testcases;cin>>Testcases;while(Testcases--)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int f(ll i,ll j,string a,string b,vector<vector<int> >&dp)
{
	if(i == a.length() && j == b.length()) {
		return 1;
	}
	if(i == a.length() || j == b.length())
	{
		return 0;
	}
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	int ans = 0;
	if(a[i] == b[j] || b[j] == '?')
	{
		ans = f(i+1,j+1,a,b,dp);
	}
	if(b[j] == '*')
	{
		ans = f(i+1,j,a,b,dp) | f(i,j+1,a,b,dp);
	}
	return ans = dp[i][j];
}
int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    fastIO
    string a,b;cin>>a>>b;
    vector<vector<int> >dp;
    range(0,a.length(),1,i)
    {
    	vector<int> t;t.resize(b.length()+1,-1);
    	dp.pb(t);
    }
    print(f(0,0,a,b,dp));
	return 0;
}