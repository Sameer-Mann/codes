#include <iostream>
using namespace std;
int maxSum(int a[],int n){
	int dp[1000] = {0};
	int max_so_far = a[0]>0?a[0]:0;
	for (int i = 1; i < n; ++i)
	{
		dp[i] = dp[i-1] + a[i];
		if(dp[i] < 0){
			dp[i] = 0;
		}
		max_so_far = max(dp[i],max_so_far);
	}
	return max_so_far
}
int main()
{
	return 0;
}
