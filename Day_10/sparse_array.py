"""
sparse array hackerrank 
O(n^2)
"""

n=int(input())
l=list()
for i in range(n):
    temp=input()
    l.append(temp)

k=int(input())

for j in range(k):
    temp=input()
    c=l.count(temp)
    print(c)