#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define range(s,e,d,i) for (ll i =(s); i <=(e); i+=(d))
#define range2(s,e,d,i) for (ll i = s; i >= e; i -= d)
#define vll vector<ll>
#define print(a) cout<<a<<"\n";
#define input(a,n) range(0,n-1,1,i) cin>>a[i];
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void f(ll i,ll j,string a,string b,vector<vll>&dp,ll lcs,vll &st)
{
	if(lcs == 0)
	{
		return;
	}
	if(a[i-1] == b[j-1])
	{
		st.pb(i-1);
		f(i-1,j-1,a,b,dp,lcs-1,st);
	}
	else{
		if(dp[i-1][j]>dp[i][j-1])
		{
			f(i-1,j,a,b,dp,lcs,st);
		}
		else
		{
		f(i,j-1,a,b,dp,lcs,st);
		}
	}
	return;
}
int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
	fastIO
    string a,b;cin>>a>>b;
    ll n=a.length(),m=b.length();
	vector<vll>dp;
	range(0,n+1,1,i){
		vll t;t.resize(m+1,0);
		dp.pb(t);
	}
    range(1,n,1,i)
    {
    	range(1,m,1,j)
    	{
    		if(a[i-1] == b[j-1])
    		{
    			dp[i][j] = 1+dp[i-1][j-1];
    		}
    		else
    		{
    			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    		}
    	}
    }
    vll st;
    string ans ="";
    f(n,m,a,b,dp,dp[n][m],st);
    for(auto i:st)
    {
		ans = a[i]+ans;
    }
    print(ans);
	return 0;
}