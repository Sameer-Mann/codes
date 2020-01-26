#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define range(s,e,d,i) for (ll i =(s); i <=(e); i+=(d))
#define range2(s,e,d,i) for (ll i = s; i >= e; i -= d)
#define vll vector<ll>
#define print(a) cout<<a<<"\n";
#define input(a,n) range(0,n-1,1,i) cin>>a[i];
#define mod 1000000007
#define test ll Testcases;cin>>Testcases;while(Testcases--)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    ll n,cap;cin>>n>>cap;
    vll wt,vals;wt.resize(n,0);vals.resize(n,0);
    input(wt,n);
    input(vals,n);
    vector<vll>dp;
    range(0,cap,1,i)
    {
    	vll t;t.resize(n+1,0);
    	dp.pb(t);
    }
    range(1,cap,1,i)
    {
    	range(1,n-1,1,j)
    	{
    		if(i-wt[j]>=0)
    		{
    			dp[i][j] = max(dp[i][j-1],vals[i-1]+dp[i-wt[j]][j-1]);
    		}
    	}
    }
    print(dp[cap][n-1]);
	return 0;
}