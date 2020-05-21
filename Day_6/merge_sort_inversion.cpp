/*
hackerrank larry array and hackerrank merge sort:counting inversion T(N)=O(NLlog(N))
*/
#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll merge(ll arr[],ll left,ll mid,ll right){
    ll m=mid-left+1;
    ll n=right-mid;
    ll inversion=0;
    ll L[m];
    ll R[n];

    for(ll i=0;i<m;i++){
        L[i]=arr[left+i];
    }
    for(ll j=0;j<n;j++){
        R[j]=arr[j+mid+1];
    }
    ll i = 0; 
    ll j = 0; 
    ll k = left; 
    while (i < m && j < n) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k++] = L[i++]; 
        } 
        else
        { 
            arr[k++] = R[j++]; 
            inversion=inversion + (m-i);
        } 
    } 
     while (i < m) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
return inversion;
}

ll merge_sort(ll arr[],ll lb,ll ub){
    ll inversion=0;
    //static int func=0;
    //func=func+1;

   // cout<<"call: "<<func<<endl;
    if(ub>lb){

    ll mid=(ub+lb)/2;

    /*for(int i=lb;i<=ub;i++){
        cout<<arr[i]<<" ";
    }*/
    //cout<<endl;

    inversion+=merge_sort(arr,lb,mid);
    //cout<<"Ist ccall:"<<inversion<<endl;
    inversion+=merge_sort(arr,mid+1,ub);
    //cout<<"IIst ccall:"<<inversion<<endl;
    inversion+=merge(arr,lb,mid,ub);
    //cout<<"IIIst ccall:"<<inversion<<endl;
    }
    return inversion;
}

int main(){
    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        ll arr[n];

        for(ll i=0;i<n;i++)
            cin>>arr[i];

        ll inversion = 0;
        inversion= merge_sort(arr,0,n-1);

        cout<<inversion<<endl;

        //cout<<"final inversion:"<<inversion<<endl;
        /*for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }*/
    }
}
