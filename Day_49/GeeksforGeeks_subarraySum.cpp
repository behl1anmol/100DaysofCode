/*
https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
T(n) = (n)
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,sum,flag=0;
        cin>>n>>sum;
        
        int arr[n];
        
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        int currSum=arr[0],start=0,i;
        
        for(i=1;i<=n;i++){
            
            while(currSum>sum && start<i-1){
                currSum = currSum - arr[start];
                start++;
            }
            
            if(currSum==sum){
                cout<<start+1<<" "<<i<<endl;
                flag=1;
                break;
            }
            if(i<n)
                currSum=currSum+arr[i];
        }
        if(flag==0){
            cout<<-1<<endl;
        }
    }
}