#code
def coin_change(n,coins):
    dp = [0 for x in range(n+1)]
    dp[0] = 1
    for i in range(len(coins)):
        for j in range(coins[i],n+1):
            dp[j] += dp[j-coins[i]]
    return dp[n]
for _ in range(int(input())):
    m = int(input())
    coins = sorted(map(int,input().split()),reverse=True)
    n = int(input())
    dp = [-1]*(n+1)
    print(coin_change(n,coins))