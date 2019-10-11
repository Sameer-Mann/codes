for _ in range(int(input())):
	n = int(input())
	s = str(input())
	u = str(input())
	score = 0
	for i in range(n):
		if s[i] == u[i]:
			score += 1
		else:
			if u[i] == 'N':
				continue
			else:
				i += 1
	print(score)