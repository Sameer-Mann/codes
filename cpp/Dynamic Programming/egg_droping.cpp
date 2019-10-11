#include <iostream>
#include <climits>
using namespace std;
int f(int n,int k){
    int dp[1000][1000] = {{0}};
    for(int i = 1; i <= n;i++)
    {
        dp[1][i] = i;
    }
    for(int i = 2; i <= k ;i++){
        for (int j = 1; j <= n; j++)
        {
            int ans = INT_MAX;
            for (int x = 1; x<=j; x++)
            {
                ans = min(ans,1 + max(dp[i-1][x-1],dp[i][j-x]));
            }
            dp[i][j] = ans;
        }
    }
    return dp[k][n];
}
int main() {
	//code
	int t;cin>>t;
	while(t--){
        int floors,eggs;cin>>eggs>>floors;
        cout<<f(floors,eggs)<<endl;
	}
	return 0;
}