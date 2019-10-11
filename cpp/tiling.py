def count(n,m,nums):
	if(n==0 or n<m):
		return 1
	if(n==m):
		return 2
	if(nums[n]!=None):
		return nums[n]
	
for _ in range(int(input())):
	a,b = map(int,input().split())
	nums = [None]*a
	print(count(a,b,nums))