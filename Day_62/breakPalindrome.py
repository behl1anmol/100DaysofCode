def breakPalindrome(palindromeStr):
    palindromeStr = list(palindromeStr)
    lengthStr = len(palindromeStr)
    
    ##base case#######################################
    flag=0
    for i in range(0,lengthStr):
        if palindromeStr[i] == 'a':
            flag+=1
    
    if flag==lengthStr and lengthStr>1:
        return 'IMPOSSIBLE'
    ####################################################

    for i in range(0,lengthStr//2):
        if palindromeStr[i] !='a':
            palindromeStr[i] = 'a'
            return (''.join(palindromeStr))
    
    palindromeStr[lengthStr-1] = 'b'
    if lengthStr<2:
        return ''
    else:
        return (''.join(palindromeStr))

if __name__=='__main__':
    inputStr = input()
    print(breakPalindrome(inputStr))

