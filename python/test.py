#code
for _ in range(int(input())):
    n,k = map(int,input().split())
    arr = list(map(int,input().split()))
    ans = []
    if n % k == 0:
        for i in range(0,n,k):
            t = arr[i:i+k]
            t.reverse()
            ans += t
    elif n > k:
        i = 0
        count = k//n
        rem = k % n
        while i < n - rem:
            t = arr[i:i+k]
            t.reverse()
            ans += t
            i += k
        ans += arr[n-rem+1:]
    else:
        i = 0
        count = n//k
        rem = n % k
        while i < n - rem:
            t = arr[i:i+k]
            t.reverse()
            ans += t
            i += k
        ans += arr[n-rem+1:]
    print(*ans)