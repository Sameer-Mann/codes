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
ll f()
{
	if(x == 0) return 0;
	if(i == wt.size())
	{
		if(x == 0) return 0;
		return -INT_MAX;
	}
	ll ans = -1;

}
int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    ll n,m,x;cin>>n>>m>>x;
    vll wt,c;wt.resize(n,0);c.resize(n,0);
    input(wt,n);
    input(c,n);
    print(f(wt,c));
	return 0;
}