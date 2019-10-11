import sys
def f(n,x,a):
	count = 0
	for i in range((1<<n)):
		pos = 0
		xor = 0
		while i > 0:
			if i&1:
				xor = xor ^ a[n - pos - 1]
			i = i>>1
			pos += 1
		if xor == x:
			count += 1
	return count
def main():
	n,q = map(int,sys.stdin.readline().split())
	a = list(map(int,sys.stdin.readline().split()))
	for _ in range(q):
		l,x = map(int,sys.stdin.readline().split())
		print(f(l,x,a))
main()