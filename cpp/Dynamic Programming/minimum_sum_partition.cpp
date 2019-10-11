#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int f(int n,int i,int a[],int sm,int s)
{
    if(i == n)
    {
        return abs(s-2*sm)
    }
    if(dp[i][sm] != -1)
    {
        return dp[i][sm];
    }
    return min(f(n,i+1,a,sm+a[i],s),f(n,i+1,a,sm,s));
}
int main() {
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int a[n];
        int sum = 0;
        for(int i = 0 ; i < n; i++)
        {
            cin>>a[i];
            sum += a[i];
        }
        memset(dp,-1,sizeof(dp));
        cout<<f(n,0,a,0,s)<<endl;
    }
    return 0;
}