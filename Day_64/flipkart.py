def funcSort(arr,n,k):
    lenA = k
    lenB = n-k
    arrA = [0] * k
    arrB = [0] * (n-k)

    for i in range(k):
        arrA[i] = arr[i]
    
    for i in range(k,n):
        arrB[i-k] = arr[i]
    
    arrA.sort()
    arrB.sort()

    for i in range(n):
        if(i < k):
            arr[i] = arrA[i]
        else:
            arr[i] = arrB[lenB - 1]
            lenB -= 1
    
    for i in range(n):
        print(arr[i], end = " ")

n,k = map(int,input().strip().split(" "))
arr = list(map(int,input().strip().split(" ")))

funcSort(arr,n,k)