mod = 1000000007
def f(l,r,i,sm,dp):
    if i==len(l):
        if (sm%2)==1:
            return 1
        else:
            return 0
    if dp[i][sm]!=-1:
        return dp[i][sm]
    ans=f(l,r,i+1,sm+l[i],dp)%mod+f(l,r,i+1,sm+r[i],dp)%mod
    dp[i][sm]=ans%mod
    return ans
def main():
	n=int(input())
	l=[0]*n
	r=[0]*n
	for i in range(n):
		l[i],r[i]=map(int,input().split())
	m=0
	for i in range(n):
		m+=max(l[i],r[i])
	dp=[]
	ll=[-1]*(m+1)
	for _ in range(n+1):
		dp.append(list(ll))
	print(f(l,r,0,0,dp))
main()