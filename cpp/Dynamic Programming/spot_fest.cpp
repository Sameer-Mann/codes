#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define print(a) cout<<a<<endl;
#define range(s,e,d,i) for (ll i =(s); i <= (e); i+=(d))
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define umll unordered_map<string,ll>
// ll dp[100000][3][4];
umll dp;
ll mod = 1000000007;
ll fg(ll f,ll h,ll d,ll n)
{
	if(d == n) return 1;
	string st = to_string(f)+" "+to_string(h)+" "+to_string(d);
	if(dp.find(st) != dp.end()) return dp[st];
	// if(dp[d][f][h] != -1) return dp[d][f][h];
	ll ans1=0,ans2=0,ans3 = 0;
	if(d-f>=2 || f == -1)
	{
		ans1 = fg(d,h,d+1,n);
	}
	if(d-h>=3 || h == -1)
	{
		ans2 = fg(f,d,d+1,n);
	}
	ans3 = fg(f,h,d+1,n);
	// return dp[d][f][h] = (ans3+ans2+ans1)%mod;
	return dp[st] =(ans3+ans2+ans1)%mod;
}
int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    fastIO
    ll n;cin>>n;
    ll dp[n+1][3];
    memset(dp,0,sizeof(dp));
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    range(2,n,1,i)
    {
    	dp[i][0] = (dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%mod;
    	dp[i][1] = (dp[i-1][0]+dp[i-1][2])%mod;
    	dp[i][2] = (dp[i-1][0]+dp[i-1][1] - 2*dp[i-2][2])%mod;
    }
    // print(fg(-1,-1,0,n));
    print((dp[n][0]+dp[n][1]+dp[n][2])%mod)
	return 0;
}