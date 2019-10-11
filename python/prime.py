from fractions import gcd
MOD = 10**9 + 7

# Prime - seave to calculate primes upto n in order n(log(n))
# exp(x,y,MOD): return (x^y)%N

def Prime_Seave(n,arr):
	ans = []
	arr[0] = False
	i = 4
	while i < n + 1:
		arr[i-1] = False
		i += 2
	i = 3
	while i*i < n+1:
		for k in range(i*i,n,2*i):
			arr[k-1] = False
		i += 1

	i = 1
	while i < n:
		if arr[i]:
			ans.append(i+1)
		i += 1
	return ans

def isPrime(n):
	if n <= 1:
		return False
	if n <= 3:
		return False
	if(n%2 == 0 or n%3 == 0):
		return False
	i = 5
	while i*i < n:
		if(n%i == 0 or n %(i+2) == 0):
			return False
		i += 6
	return True

def factorial(n):
	if n == 1:
		return 1
	return n*factorial(n-1)
# function to count no of 1 in binary representation of a decimal no.
def countSetBits(n): 
  
    # base case 
    if (n == 0): 
        return 0
    else: 
        return 1 + countSetBits(n & (n - 1))

def decimalToBinary(num):
    if num > 1:
        decimalToBinary(num // 2)
    print(num % 2, end='')

# It return an array with pairs having sum equal to the given value
def printPairs(arr, arr_size, sum): 
    s = set()
    ans = []
    for i in range(0,arr_size): 
        temp = sum-arr[i] 
        if (temp in s): 
            ans.append((temp,arr[i]))
        s.add(arr[i])
    return ans

# multiplys two numbers repersented as strings and return a new string
def multiply(num1, num2): 
    len1 = len(num1) 
    len2 = len(num2) 
    if len1 == 0 or len2 == 0: 
        return "0"
    result = [0] * (len1 + len2) 
    i_n1 = 0
    i_n2 = 0
    for i in range(len1 - 1, -1, -1): 
        carry = 0
        n1 = ord(num1[i]) - 48
        i_n2 = 0
        for j in range(len2 - 1, -1, -1): 
            n2 = ord(num2[j]) - 48
            summ = n1 * n2 + result[i_n1 + i_n2] + carry 
            carry = summ // 10
            result[i_n1 + i_n2] = summ % 10
            i_n2 += 1
        if (carry > 0): 
            result[i_n1 + i_n2] += carry 
        i_n1 += 1
    i = len(result) - 1
    while (i >= 0 and result[i] == 0): 
        i -= 1
    if (i == -1):
        return "0"
    s = "" 
    while (i >= 0): 
        s += chr(result[i] + 48) 
        i -= 1
    return s

for _ in range(int(input())):
	n = int(input())