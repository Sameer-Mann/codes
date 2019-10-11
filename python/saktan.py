import sys
def f(n,m,rows,columns):
	odd_count = 0
	for i in range(1,n+1):
		for j in range(1,m+1):
			count = 0
			if rows.get(i) != None:
				count += rows[i]
			if columns.get(j) != None:
				count += columns[j]
			if count%2 != 0:
				odd_count += 1
	print(odd_count)
def c(rows,columns,q,n,m):
	for _ in range(q):
			i,j = map(int,sys.stdin.readline().split())
			if rows.get(i) == None:
				rows[i] = 1
			else:
				rows[i] += 1
			if columns.get(j) == None:
				columns[j] = 1
			else:
				columns[j] += 1
	columns_count = [0,0]
	for j in columns.keys():
		columns_count[columns[j]%2] += 1
	ans = 0
	for i in range(1,n+1):
		if rows[i]%2 == 0:
			ans += columns_count[1]
		else:
			ans += columns_count[0]
	# f(n,m,rows,columns)
def main():
	for _ in range(int(sys.stdin.readline())):
		n,m,q = map(int,sys.stdin.readline().split())
		c({},{},q,n,m)	
main()