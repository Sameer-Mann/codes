#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define range(s,e,d,i) for (ll i =(s); i <= (e); i+=(d))
#define print(a) cout<<a<<"\n";
#define test ll Testcases;cin>>Testcases;while(Testcases--)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll dp[100][100][100];
ll f(ll a,ll b,ll c)
{
	if(a < 0 or b < 0 or c< 0) return INT_MAX;
	if(a==0 and b == 0) return c;
	if(a == 0 and c == 0) return b;
	if(b == 0 and c == 0) return a;
	if(dp[a][b][c] != -1) return dp[a][b][c];
	ll ans1 = f(a-1,b-1,c+1);
	ll ans2 = f(a+1,b-1,c-1);
	ll ans3 = f(a-1,b+1,c-1);
	return dp[a][b][c]=min(ans1,min(ans3,ans2));
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
    	string s;cin>>s;
    	ll t[] = {0,0,0};
    	range(0,s.length()-1,1,i) ++t[(int)(s[i])-(int)('a')];
    	memset(dp,-1,sizeof(dp));
    	print(f(t[0],t[1],t[2]))
    }
	return 0;
}