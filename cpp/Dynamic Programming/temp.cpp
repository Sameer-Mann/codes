#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int f(int n,int a[],int sum)
{
    int ans = INT_MAX;
    for(int j = 1; j <= (1<<n) - 1 ; ++j)
    {
        int i = j;
        int sm = 0,pos = 0;
        while(i > 0)
        {
            if(i&1)
            {
                sm += a[n-pos-1];
            }
            pos++;
            i = i>>1;
        }
        ans = min(ans,abs(sum - 2*sm));
    }
    return ans;
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
        cout<<f(n,a,sum)<<endl;
    }
    //code
    return 0;
}