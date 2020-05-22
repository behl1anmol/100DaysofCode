#include<bits/stdc++.h>

using namespace std;

int func_knap(int W, int w[], int v[], int n, int** dp){

    if(n==0 || W==0)
        return 0;

    if(dp[n][W] != -1)
        return dp[n][W];
    if(w[n] > W){
        dp[n][W]=func_knap(W,w,v,n-1,dp);
        return dp[n][W];
    }
    dp[n][W]=max( (v[n] + func_knap(W-w[n],w,v,n-1,dp)) , func_knap(W,w,v,n-1,dp) );
    return dp[n][W];        
}

int func_memorization(int W,int w[], int v[], int n){
     
     int **dp;
     
     dp=new int*[n];

     for(int i=0;i<n;i++){
         dp[i]= new int[W+1];
     }

     for(int i=0;i<n;i++){
         for(int j=0;j<=W;j++){
             dp[i][j]=-1;
         }
     }
     return func_knap(W,w,v,n-1,dp);    
}
int main(){

    int v[]={60, 100, 120};

    int w[]={10, 20, 30};

    int W=50;

    int n=3;

    cout<<"answer:"<<func_memorization(W,w,v,n);

    return 0;
}