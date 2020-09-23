t = int(input())

while t:
    n = int(input())
    ans = 0
    for i in range(n+1):
        if i%2 == 0:
            ans+=1
        else:
            ans+=ans
    print(ans)
    t-=1


