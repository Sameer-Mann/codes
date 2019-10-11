for _ in range(int(input())):
	a = str(input())
	b = str(input())
	n = len(a)
	m = len(b)
	i = 0
	while(i < n):
		for j in b:
			if j == a[i]:
				continue
			else:
				i += 1
	if a==b:
		print("YES")
	else:
		print("NO")