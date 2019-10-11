def f(n,i,sm,a,s,dp):
	if i == n:
		return abs(s - 2*sm)
	if dp[i][sm] != -1:
		return dp[t]
	dp[i][sm] = min(f(n,i+1,sm+a[i],a,s,dp),f(n,i+1,sm,a,s,dp))
	return dp[i][sm]
def main():
	for _ in range(int(input())):
		n = int(input())
		a = list(map(int,input().split()))
		s = sum(a)
		dp = [list([-1]*(s+1)) for _ in range(n+1)]
		print(f(n,0,0,a,s,dp))
		# print(min(map(lambda x:abs(s-2*x),dp.values())))
main()