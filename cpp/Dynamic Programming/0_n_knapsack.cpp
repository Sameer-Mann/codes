#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mkp make_pair
#define range(s,e,d,i) for (ll i =(s); i <=(e); i+=(d))
#define range2(s,e,d,i) for (ll i = s; i >= e; i -= d)
#define vll vector<ll>
#define print(a) cout<<a<<"\n";
#define input(a,n) range(0,n-1,1,i) cin>>a[i];
#define test ll Testcases;cin>>Testcases;while(Testcases--)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    fastIO
    ll n,cap;cin>>n>>cap;
    vll wt,vals;wt.resize(n,0);vals.resize(n,0);
    input(wt,n);
    input(vals,n);
    // vector<pair<ll,ll> >s;
    // range(0,n-1,1,i){
    	// s.pb(mkp(wt[i],vals[i]));
    // }
    // sort(s.begin(),s.end());
    // ll m = s[s.size()-1].first;
    ll dp[cap+1];
    memset(dp,0,sizeof(dp));
    range(0,cap,1,i)
    {
    	range(0,n,1,j)
    	{
    		if(wt[j]<=i)
    		{
    			dp[i] = max(dp[i],vals[j]+dp[i-wt[j]]);
    		}
    	}
    }
    // range(0,cap,1,i) print(dp[i]);
    print(dp[cap]);
	return 0;
}