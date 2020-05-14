/* 
https://practice.geeksforgeeks.org/problems/find-first-set-bit-1587115620/1/?track=SPCF-BitMagic&batchId=154
T(n)=O(n)*/
#include<bits/stdc++.h>
using namespace std;

unsigned int getFirstSetBit(int n){
    
    int j=0;
    
    if(n==0)
        return 0;
    
    while(1){
        if(n&1==1){
            j++;break;
        }
        j+=1;
        n=n>>1;
    }
    return j;
    
    
}


int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        printf("%u\n", getFirstSetBit(n));
    }
	return 0;
}
