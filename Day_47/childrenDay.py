def candies(input1,input2,input3):
    n=input1
    k=input2
    arr=input3

    arr.sort(reverse=True)

    return arr[k-1]

ans = candies(6,4,[100,20,40,50,50,20])
print(ans)