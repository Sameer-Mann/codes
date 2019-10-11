def count(pos,n,steps):
	if pos == n:
		return 1
	for i in range(pos,n):
		ans = 1 + count(pos+steps[i],n,steps)
for _ in range(int(input())):
	n = int(input())
	steps = list(map(int,input().split()))
	count(i,n,steps)