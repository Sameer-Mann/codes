#include <iostream>
#include <bits/stdc++.h>
#include <climits>
using namespace std;
int a[100][100];
int dp[100][100];
int f(int n,int i,int j)
{
    if(i == n)
    {
        return a[i][j];
    }
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if(j > n || i > n || j < 1)
    {
        return -INT_MAX;
    }
    int ans1 = a[i][j] + f(n,i+1,j+1);
    int ans2 = a[i][j] + f(n,i+1,j);
    int ans3 = a[i][j] + f(n,i+1,j-1);
    int ans = max(ans1,max(ans2,ans3));
    return dp[i][j] = ans;
}
int g(int n)
{
    int ans = -INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans,f(n,1,i));
    }
    return ans;
}
int main() {
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        memset(a,0,sizeof(a));
        for(int i = 1 ; i <= n; i++)
        {
            for(int j = 1 ;j <= n; j++)
            {
                cin>>a[i][j];
            }
        }
        memset(dp,-1,sizeof(dp));
        cout<<g(n)<<endl;
    }
    return 0;
}