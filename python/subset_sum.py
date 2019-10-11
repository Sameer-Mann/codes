def f(i,sm,a,s,dp,n):
    if i == n:
        return 2*sm == s
    if dp[i][sm] != -1:
        return 2*dp[i][sm] == s
    dp[i][sm] = f(i+1,sm,a,s,dp,n) or f(i+1,sm+a[i],a,s,dp,n)
    return dp[i][sm]
for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    s = sum(a)
    dp = [list([-1]*(s+1)) for _ in range(n+1)]
    if f(0,0,a,s,dp,n):
        print("YES")
    else:
        print("NO")