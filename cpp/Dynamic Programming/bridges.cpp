#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define range(s,e,d,i) for (ll i =(s); i <= (e); i+=(d))
#define fst first
#define sd second
#define vll vector<ll>
#define print(a) cout<<a<<"\n";
#define input(a,n) range(0,n-1,1,i) cin>>a[i][0];
#define input1(a,n) range(0,n-1,1,i) cin>>a[i][1];
#define test ll Testcases;cin>>Testcases;while(Testcases--)
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    test
    {
    	ll n;cin>>n;
    	vector<pair<ll,ll> >b;
    	range(0,n-1,1,i){
    		ll t;cin>>t;
    		b.pb(make_pair(t,0));
    	}
    	range(0,n-1,1,i){
    		ll t;cin>>t;
    		b[i].second = t;
    	}
    	sort(b.begin(),b.end());
    	ll dp[1000] = {1};
    	range(0,n-1,1,i) dp[i]=1;
    	range(1,n-1,1,i)
    	{
    		range(0,i-1,1,j)
    		{
    			if(b[j].sd <= b[i].sd){
    				dp[i] = max(1+dp[j],dp[i]);
    			}
    		}
    	}
    	ll mx = -1;
    	range(0,n-1,1,i) mx=max(dp[i],mx);
    	print(mx)
    }
	return 0;
}