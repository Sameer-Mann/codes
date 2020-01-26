#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define print(a) cout<<a<<endl;
#define range(s,e,d,i) for (ll i =(s); i <= (e); i+=(d))
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    ll n;cin>>n;
    ll a[n];memset(a,-1,sizeof(a));
    range(0,n-1,1,i)
    {
    	cin>>a[i];
    }
    ll ct=0;
    range(0,n-1,1,i)
    {
    	range(0,n-1,1,j)
    	{
    		if(i!= j && (a[i]&a[j])==0){
    			ct++;
    		}
    	}
    }
    cout<<ct<<endl;
	return 0;
}