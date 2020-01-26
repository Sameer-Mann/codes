#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define range(s,e,d,i) for (ll i =(s); i <= (e); i+=(d))
#define vll vector<ll>
#define print(a) cout<<a<<"\n";
#define input(a,n) range(0,n-1,1,i) cin>>a[i];
#define test ll Testcases;cin>>Testcases;while(Testcases--)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll mod = 1000000007;
int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    fastIO
    test
    {
    	ll m;cin>>m;
    	vll a;
    	range(0,m-1,1,i){
    		ll t;cin>>t;
    		a.pb(t);
    	}
    	sort(a.begin(),a.end());
    	ll n;cin>>n;
    	ll dp[n+1];memset(dp,0,sizeof(dp));
    	dp[0]= 1;
    	range(0,m-1,1,i)
    	{
    		range(a[i],n,1,j)
    		{
	    		dp[j] +=dp[j-a[i]];
	    		dp[j] %= mod;
    		}
    	}
    	print(dp[n])
    }
	return 0;
}