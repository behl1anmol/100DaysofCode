/*
https://practice.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1/?track=SPCF-BitMagic&batchId=154
T(n) = O(n)
*/

#include <bits/stdc++.h>
using namespace std;

bool checkKthBit(long long n, int k){
    
    int temp=n>>k;
    
    if(temp&1)
        return 1;
    else
        return 0;
    
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    long long n;
	    cin>>n;
	    int k;
	    cin>>k;
	    
	    if(checkKthBit(n, k))
	        cout << "Yes" << endl;
	    else
	        cout << "No" << endl;
	}
	return 0;
}  /