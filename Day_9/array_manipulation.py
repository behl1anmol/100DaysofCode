"""array manipulation on hackerrank
T(n)=O(n)
S(n)=O(1)
"""
n,m=[int(i) for i in input().split(" ")]
arr=[0]*(n+1)
for i in range(m):
    a,b,k=[int(i) for i in input().split(" ")]
    arr[a]+=k
    if((b+1)<=n): arr[b+1]-=k
maximum=0 
temp=0
for i in arr:
   temp=temp+i
   if(maximum<temp): maximum=temp
print(maximum)