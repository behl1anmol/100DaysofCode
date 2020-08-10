def collectMaxApples(input1,input2):
    input2.sort()
    max=0
    for i in range(0,input1):
        t = input2[i]*(input1-i)
        if t>max:
            max=t
    return max

print(collectMaxApples(3,[80,48,82]))