for _ in range(int(input())):
	n = int(input())
	a = list(map(int,input().split()))
	counts = []
	for i in range(n):
		count = 0
		for j in range(i):
			if a[j]%a[i] == 0:
				count += 1
		counts.append(count)
	print(max(counts))