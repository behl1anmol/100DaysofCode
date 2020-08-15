def checkPalindrome(temp): #checking palindrome
    length = len(temp)
    if length==1:
        return True
    for i in range(length//2): #executing till length
        if temp[i] != temp[-i-1]: #comparing from front and back
            return False
    return True

inputString = input()

#function to print palindromes
def printPalindromes(temp):
    for i in range(1,len(temp)-2): #leave last two elements and check string from index 1
        if checkPalindrome(temp[:i]):  #check smallest palindrome upto i
            for j in range(i+1,len(temp)): 
                if checkPalindrome(temp[i:j]) and checkPalindrome(temp[j:]): #check next parts for palindrome
                    print(temp[:i])
                    print(temp[i:j])
                    print(temp[j:])
                    return
    print("not possible")

printPalindromes(inputString)

    