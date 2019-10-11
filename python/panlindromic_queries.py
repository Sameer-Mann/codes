def f(s,i,j,d):
    if i >= j:
        return True
    if d.get((i,j)) != None:
        return d[(i,j)]
    if s[i] == s[j]:
        d[(i,j)] = f(s,i+1,j-1,d)
    else:
        d[(i,j)] = False
    return d[(i,j)]
	# temp = s[start:end+1]
	# if temp == temp[::-1]:
	# 	return True
def main():
	n = int(input())
	s = input()
	d = {}
	for _ in range(int(input())):
		i,j = map(int,input().split())
		t = (i-1,j-1)
		if d.get(t) != None:
			if d[t]:
				print("YES")
			else:
				print("NO")
		else:
			if f(s,i-1,j-1,d):
				print("YES")
			else:
				print("NO")
main()