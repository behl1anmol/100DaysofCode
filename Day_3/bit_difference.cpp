/*
https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1/?track=SPCF-BitMagic&batchId=154

T(n)=O(n)
*/

#include<bits/stdc++.h>
using namespace std;

int countBitsFlip(int a, int b){
    
    int c=a^b;
    
    if(c==0){
        return 0;
    }
    int sum=0;
    while(c){
        if(c&1){
            sum=sum+1;
        }
        c=c>>1;
    }
    return sum;
    
}

int main()
{
	int t;
	cin>>t;
	while(t--) 
	{
		int a,b;
		cin>>a>>b; 

		cout<<countBitsFlip(a, b)<<endl;
	}
	return 0;
}  