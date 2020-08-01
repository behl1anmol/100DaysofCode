/*
leetcode minimum smallest missing number
T(n) = O(n)
S(n) = O(1)
*/
#include<bits/stdc++.h>

using namespace std;

void swap(int *p, int *p1){
    int t= *p;
    *p = *p1;
    *p1 = t;
}
int main(){
    int n;
    cin>>n;

    int arr[n+1];

    for(int i=1;i<n+1;i++){
        cin>>arr[i];
    }

    for(int i=1;i<n+1;i++){
        int change = arr[i];
        while((arr[i]>=1 && arr[i]<=n) && arr[i]!=arr[change]){
            swap(&arr[i],&arr[change]);
            change = arr[i];
        }
    }

    for(int i=1;i<n+1;i++){
        if(i != arr[i]){
            cout<<i;
            break;
        }
    }
}