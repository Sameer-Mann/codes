#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define print(a) cout<<a<<endl;
#define range(s,e,d,i) for (ll i =(s); i <= (e); i+=(d))
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define umll unordered_map<string,ll>
umll dp;
ll gcd(ll a,ll b)
{
	if(a == 0){return b;}
	return gcd(b%a,a);
}
ll f(ll a[],ll i,ll mask,ll n)
{
	if(i == n)return 0;
	string st = to_string(mask)+" "+to_string(i);
	if(dp.find(st)!=dp.end()) return dp[st];
	bool fl = true;
	ll ans = f(a,i+1,mask,n);
	range(0,n-1,1,j)
	{
		if(((mask)&(1<<j))>0){
			if(gcd(a[j],a[i])!=1){
				fl=false;
				break;
			}
		}
	}
	if(fl){
		ans = max(ans,1+f(a,i+1,mask|(1<<i),n));
	}
	return dp[st]=ans;
}
int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    fastIO
    ll n;cin>>n;
    ll a[n];memset(a,0,sizeof(a));
    range(0,n-1,1,i) cin>>a[i];
    dp.clear();
    print(f(a,0,0,n))
	return 0;
}