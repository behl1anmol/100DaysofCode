/* 
https://practice.geeksforgeeks.org/problems/rightmost-different-bit-1587115621/1/?track=SPCF-BitMagic&batchId=154
T(n) = O(1)
*/

#include <bits/stdc++.h>
using namespace std;
 

int getRightMostSetBit(int n)
{
    return log2(n & -n) + 1; 
}
 


int posOfRightMostDiffBit(int m, int n)
{
    
    int k=m^n;
    
    return log2(k & -k) +1;
    
    
}


int main()
{   
    int t;
    cin>>t; 
    while(t--)
    {
         int m,n;
         cin>>m>>n; 
         cout << posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
}  