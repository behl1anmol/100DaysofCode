t = int(input())
l = 0
r = 0
def checker(arr):
    d = dict()
    for i in arr:
        print(i)
        if i in d.keys():
            d[i]+=1
        else:
            d[i] = 1
    return d

for i in range(t):
    n = int(input())
    temp1 = input().rstrip().split(" ")
    arr = [int(i) for i in temp1]
    d = dict()
    print("array:",arr)
    print(d)
    d= checker(arr)
    check = all(value == 1 for value in d.values())
    if not check:
        print("NO")
        d= {}
        arr=[]
        continue
    temp =arr[0]
    #print(arr)
    while(r<n-1):
        r+=1
        #print("r:",r)
        temp = temp | arr[r]
        if temp in d.keys():
            d[temp]+=1
        else:
            d[temp] = 1    
    print("dictionary before",d)
    temp = arr[r]
    l = arr[r-1]
    while(l>=0):
        temp = temp | arr[l]
        if temp in d.keys():
            d[temp]+=1
        else:
            d[temp] = 1
        l= l-1            
    check =  all(value == 1 for value in d.values())
    print("dictionary:",d)
    if check:
        print('YES')
    else:
        print('NO')
    d = {}
    arr=[]
    l = 0
    r = 0              