import sys
l=list(map(int,input().split()))
ans = [0 for i in range(len(l))]  
if len(l)==0 or l[0]==0: 
    print(-1)
else:
    for i in range(1, len(l)): 
        ans[i] = sys.maxsize
        for j in range(i): 
            if (i <= j+l[j]) and (l[j] != sys.maxsize): 
                ans[i] = min(ans[i],ans[j]+1) 
                break
    print (ans[len(l)-1])
