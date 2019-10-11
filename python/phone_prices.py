import sys
# cook your dish here
for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    nums = []
    mn = sys.maxsize
    count  = 0
    for i in range(5):
        if a[i] < mn:
            count += 1
            mn = a[i]
        nums.append(a[i])
    for i in range(5,n):
        if a[i] < mn:
            count+= 1
        nums = nums[1:]
        nums.append(a[i])
        mn = min(nums)
    print(count)
