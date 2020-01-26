#include<iostream>
using namespace std;
long long int modulo = 1000000007;
long long int tiles(int n,int m,int dp[]){
    if(n==0){
        return 1;
    }
    if(n==m){
        return 2;
    }
    if(dp[n]!= -1){
        return dp[n];
    }
    if(n>=m){
        dp[n] = ((tiles(n-1,m,dp))%modulo + tiles(n-m,m,dp)%modulo)%modulo;
    } else {
        dp[n] = tiles(n-1,m,dp)%modulo;
    }
    return dp[n];
}
int main() {
    int t;cin>>t;
    while(t--){
        int n;int m;
        cin>>n>>m;
        int dp[100000] = {-1};dp[0] = 1;
        cout<<tiles(n,m,dp)<<endl;
    }
	return 0;
}