#include<iostream>
using namespace std;
long long int modulo = 1000000007;
int countWays(int n, int m) 
{ 
    long long int count[n + 1]; 
    count[0] = 0; 
    for (int i = 1; i <= n; i++) { 
        if (i > m) 
            count[i] = (count[i - 1] + count[i - m])%modulo; 
  
        else if (i < m) 
            count[i] = 1; 
        else
            count[i] = 2; 
    } 
    return count[n]; 
} 
int main() {
    int t;cin>>t;
    while(t--){
        int n;int m;
        cin>>n>>m;
        cout<<countWays(n,m)<<endl;
    }
	return 0;
}