/*core dump*/
#include<bits/stdc++.h>

using namespace std;


bool func_subsetSum(int arr[],int n,int sum,int** dp){
    
    if(sum==0){
        return true;
    }
    if(sum>0 && n==0){
        return false;
    }

    if(dp[n][sum]!=-1)
        return (dp[n][sum]==1? true:false);


    if(arr[n-1]>sum){
        dp[n][sum] = (func_subsetSum(arr,n-1,sum,dp)== true ? 1 : 0 );
        return dp[n][sum]==1?true:false;
    }
    dp[n][sum]= (func_subsetSum(arr,n-1,sum,dp) || func_subsetSum(arr,n-1,sum-arr[n-1],dp) == true ? 1:0);

    return (dp[n][sum] == 1 ? true:false);     
}
bool func_memorization(int arr[],int n, int sum){
     
     int **dp;
     
     dp=new int*[n+1];

     for(int i=0;i<n+1;i++){
         dp[i]= new int[sum + 1];
     }

     for(int i=0;i<n+1;i++){
         for(int j=0;j<=sum;j++){
             dp[i][j]=-1;
         }
     }
     return func_subsetSum(arr, n, sum, dp);    
     
}

int main(){

    int arr[]={3,34,4,12,5,2};

    int sum=9;

    int n=6;

    if(func_memorization(arr,n,sum)==true)
        cout<<"YES";
    else
    {
            cout<<"NO";
    }
        

}