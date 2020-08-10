def frequency(input):
    res = {i:input.count(i) for i in set(input)}
    ans=""
    for k,v in sorted(res.items()):
        ans=ans+k+str(v)
    return(ans)

    