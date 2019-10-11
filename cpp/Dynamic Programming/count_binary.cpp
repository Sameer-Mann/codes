#include<iostream>
using namespace std;
long long int fib(int n){
    long long int dp[n+1];
    dp[1] = 2;dp[2] = 3;
    for(int i=3;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main() {
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<fib(n)<<endl;
    }
	return 0;
}