def f(n,x,a):
	val = x%n
	if x>=n:
		t = (x//n)%3
		if n%2 == 1 and t == 0:
			a[n//2] = 0
		for _ in range(t):
			for i in range(n):
				a[i] = a[i]^a[n-i-1]
	for i in range(val):
		a[i] = a[i]^a[n-i-1]
	print(*a)
def main():
	for _ in range(int(input())):
		n,x = map(int,input().split())
		arr = list(map(int,input().split()))
		f(n,x,arr)
main()