n = int(input())
l = list(map(int,input().strip().split()))

l.sort()

closest = l[0]
curr = 0

for i in range(len(l)):
    curr = l[i] * l[i]
    if(curr <= (closest*closest)):
        closest = l[i]

print(closest)