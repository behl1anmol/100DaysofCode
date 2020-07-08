#LEETCODE lemonadechange
def lemonadeChange(bills)->bool:
    d=dict()
    for i in range(len(bills)):
        if bills[i]==5:
            if bills[i] in d:
                d[bills[i]]+=1
            else:
                d[bills[i]]=1
        else:
            if bills[i] in d:
                d[bills[i]]+=1
            else:
                d[bills[i]]=1
            change = bills[i]-5
            for j in sorted(d, reverse=True):
                if change==0:
                    break
                else:
                    if d[j]>=1:
                        while d[j]>0:
                            if change-j>=0: 
                                change-=j
                                d[j]-=1
                            else:
                                break    
            if change!=0:
                return False
    if change==0:
        return True
    else:
        return False


print(lemonadeChange([5,5,10,20,5,5,5,5,5,5,5,5,5,10,5,5,20,5,20,5]))
