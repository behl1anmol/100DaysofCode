def halindrome(input1,input2):
    s=input1
    arr=input2
    count=0

    for i in range(0,s):
        temp = arr[i]
        rev = temp[::-1]
        length = len(temp)
        check = length%2

        if rev==temp and length>=2: #condition 1
            count+=1
            continue

        #dividing strings
        div = length//2
        if check == 0: #if len even S1 and S2
            left = temp[ : div]
            right = temp[(div) :  ]
        else:#if len odd S1 and S2
            right = temp[ (div+1):]
            left = temp[: div]
        #checking for S1 or S2
        if left == left[::-1] or right == right[::-1]:
            count+=1
            continue
    return count

ans = halindrome(4,["hahshs","ccc","as","hah"])
print(ans)



