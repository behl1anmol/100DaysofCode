import math
def SeiveofErathones(l, s): 
	maximumValue = max(l) 
	seive = [True for i in range(maximumValue + 1)] 
	seive[0] = False
	seive[1] = False
	for i in range(2, math.ceil(math.sqrt(maximumValue))): 
		if (seive[i] == True): 
			for j in range(2 * i, maximumValue + 1, i): 
					seive[j] = False
	maxPrime = -10**9
	for i in range(s): 
		if (seive[l[i]] == True): 
			maxPrime = max(maxPrime, l[i]) 
		
	return maxPrime  

inputArray =  list(map(int,input().strip().split(',')))
lenArray = len(inputArray) 

print(SeiveofErathones(inputArray, lenArray)) 

