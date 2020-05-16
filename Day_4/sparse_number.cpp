/*
https://practice.geeksforgeeks.org/problems/number-is-sparse-or-not-1587115620/1/?track=SPCF-BitMagic&batchId=154

T(n)=O(1)

*/
#include<iostream>
using namespace std;

bool isSparse(int n){
    
    return !(n&(n>>1));
    
}

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        
        if(isSparse(n)){
            cout << "1" << endl;
        }
        else cout << "0" << endl;
        
    }
    return 0;
}  