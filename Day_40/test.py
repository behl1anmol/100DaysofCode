def func(arr,l,r):
    if r<l:
        return -1000000000
    ans = arr[i]
    for i in range(l+1,r+1):
        ans=ans and arr[i]
    return ans

def closestTOTarget(arr, target):
    res=100000000
    l=0
    r=len(arr)-1
    ll=[[i,j] for i in range(len(arr)) for j in range(i,len(arr))]

    for i in ll:
        x= abs(func(arr,i[0],i[1])-target)
        if x<=res:
            res=x
    return res            

target = 5
arr = [9,12,3,7,15]
result = closestTOTarget(arr , target)
#l=0
#r=4
#arr = [i for i in range(l,r+1)]

#ll = [[arr[i],arr[j]] for i in range(len(arr)) for j in range(i,len(arr))]
#print(ll)