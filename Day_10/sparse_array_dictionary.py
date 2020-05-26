"""
sparse array hackerrank 
O(n)
"""
n=int(input())
d=dict()
for i in range(n):
    temp=input()
    if temp in d.keys():
        d[temp]+=1
    else:
        d[temp]=1    

k=int(input())

for i in range(k):
    temp=input()
    if temp not in d.keys():
        print(0)
    else:
        print(d[temp])    