d = dict()
t= int(input())

for i in range(t):
    n = int(input())
    s =input()
    for i in s:
        if i in d.keys():
            d[i]+=1
        else:
            d[i]=1    
    check= all(value%2 == 0 for value in d.values())       
    if check:
        print("YES")
    else:
        print("NO")
    d = {}
