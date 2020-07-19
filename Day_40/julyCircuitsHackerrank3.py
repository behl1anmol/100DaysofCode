MAX = 10000003

mod = 0

prime = [0 for i in range(MAX)] 

max_map = dict() 


def power(a, n): 
	
	if n == 0: 
		return 1
	p = power(a, n // 2) % mod 
	p = (p * p) % mod 
	
	if n & 1: 
		p = (p * a) % mod 
	return p 

 
def sieve(): 
	prime[0], prime[1] = 1, 1
	for i in range(2, MAX): 
		if prime[i] == 0: 
			for j in range(i * 2, MAX, i): 
				if prime[j] == 0: 
					prime[j] = i 
			prime[i] = i 


def lcmModuloM(arr, n, k): 
	
	for i in range(n): 
		num = arr[i] 
		
		temp = dict() 
		
 
		while num > 1: 

			factor = prime[num] 

			if factor in temp.keys(): 
				temp[factor] += 1
			else: 
				temp[factor] = 1

			num = num // factor 
			
		for i in temp: 

			if i in max_map.keys(): 
				max_map[i] = max(max_map[i], temp[i]) 
			else: 
				max_map[i] = temp[i] 
			
	ans = 1
	
	for i in max_map: 
		ans = (ans * power(power(i, max_map[i]),k) ) % mod 
	return ans 

sieve() 
t = int(input())
for i in range(0,t):
    arr= []
    temp = input().rstrip().split(" ")
    n, mod, k = temp
    n = int(n)
    mod = int(mod)
    k = int(k)
    temp = input().rstrip().split(" ")
    arr = [int(i) for i in temp]
    print(lcmModuloM(arr, n, k)) 

