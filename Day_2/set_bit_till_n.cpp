/*
https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1/?track=SPCF-BitMagic&batchId=154
T(n) = O(n)
*/
#include<iostream>
using namespace std;

int countSetBits(int n){
    
int sum=0;

for(int i=0;i<=n;i++){
    sum+=__builtin_popcount(i);
}
 
 return sum;   
}


int main()
{
	 int t;
	 cin>>t;
	 while(t--) 
	 {
	       int n;
	       cin>>n; 
	       
	       cout << countSetBits(n) << endl;
	  }
	  return 0;
}  