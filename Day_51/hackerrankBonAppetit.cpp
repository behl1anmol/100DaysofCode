//T(n) = O(n)
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n,k;
    cin>>n>>k;
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int sum=0;

    for(int i=0;i<n;i++){
        if(i==k) continue;
        sum += arr[i];
    }
    int cost;
    cin>>cost;

    sum=sum/2;

    if(cost-sum==0) cout<<"Bon Appetit";
    else cout<<(cost-sum);

    return 0;
}