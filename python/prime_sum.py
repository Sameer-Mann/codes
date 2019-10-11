#code
def Prime_Seave(n):
    ans = []
    arr = [False]*n
    i = 2
    while i < n + 1:
        arr[i-1] = True
        i += 2
    i = 3
    while i*i < n+1:
        for k in range(i*i,n,2*i):
            arr[k-1] = True
        i += 1
    i = 2
    while i < n:
        if False == arr[i]:
            ans.append(i+1)
        i += 1
    return ans

def printPairs(arr, arr_size, sum): 
    s = set()
    ans = []
    for i in range(0,arr_size): 
        temp = sum-arr[i] 
        if (temp in s): 
            ans.append((temp,arr[i]))
        s.add(arr[i])
    return ans

for _ in range(int(input())):
    n = int(input())
    primes = Prime_Seave(n)
    primes = [2] + primes
    ans = printPairs(primes,len(primes),n)
    if n == 2:
        print(2,2)
    else:
        if len(ans) > 0:
            m = ans[0]
            for l in ans:
                if l[0] < m[0]:
                    m = l
            print(m[0],m[1])
        else:
            print(-1)