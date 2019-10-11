def c(rows,columns,n):
	columns_count = [0,0]
	for j in columns[1:]:
		columns_count[j%2] += 1
	ans = 0
	for i in range(1,n+1):
		if rows[i]%2 == 0:
			ans += columns_count[1]
		else:
			ans += columns_count[0]
	return ans
def main():
	for _ in range(int(input())):
		n,m,q = map(int,input().split())
		rows,columns = [0]*(n+1),[0]*(m+1)
		for _ in range(q):
			i,j = map(int,input().split())
			rows[i] += 1
			columns[j] += 1
		print(c(rows,columns,n))
main()