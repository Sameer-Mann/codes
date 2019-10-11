#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool dp[1000][1000];
bool f(int n,int i,int a[],int sm,int s)
{
    if(i == n)
    {
        return 2*sm == s;
    }
    if(dp[i][sm] != -1)
    {
        return 2*dp[i][sm] == s;
    }
    dp[i][sm] = (f(n,i+1,a,sm+a[i],s)||f(n,i+1,a,sm,s));
    return dp[i][sm];
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
        memset(dp,false,sizeof(dp));
        cout<<f(n,0,a,0,s)<<endl;
    }
    return 0;
}