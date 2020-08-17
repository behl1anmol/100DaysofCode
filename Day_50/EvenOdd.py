#Function to find different cartesian permutations
def funcCartesian(*args,rep=1):
    #ans = list()
    ans=0
    p = [list(t) for t in args] * rep
   # print(p)
    result = [[]]
    for t in p:
        result = [x+[y] for x in result for y in t ]
    for prod in result:
        #print(prod)
        if (funcTupleSum(prod)%2==0):
            print(result)
            ans+=1
    return ans

#calculate sum of tuple
def funcTupleSum(l):
    s=0
    for i in range(len(l)):
        s=s+int(l[i])
    return s

#taking input given values
lb,ub=map(int,input().split())
#inputing limit for permutations
limit=int(input())
#defining list for numbers
listNumbers=[]
for i in range(lb,ub+1):
    listNumbers.append(str(i))
#initializing counting flag
flagCounter=0
#getting total permutations
totalPermutations = funcCartesian(listNumbers,rep=limit)
#printing count MOD 1000000007 
print(totalPermutations%1000000007)