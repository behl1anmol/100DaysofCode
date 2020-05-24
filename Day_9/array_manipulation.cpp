/*array manipulation on hackerrank
T(n)=O(n)
S(n)=O(1)
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ll n,m;
    cin>>n>>m;
    ll *arr=new ll[n+1]();
    while(m--){
        ll a,b,k;
        cin>>a>>b>>k;

        arr[a]+=k;
        if((b+1)<=n) arr[b+1]-=k;
    }
    ll maximum=0,temp=0;
    for(ll i=1;i<=n;i++){
        temp=temp+arr[i];
        maximum=max(temp,maximum);
    }
    cout<<maximum;
    return 0;
}
/*
Segmentation Fault on biginput
#include<bits/stdc++.h>

using namespace std;

#define ll long long int

int main(){

    ll n,m;
    cin>>n>>m;

    ll arr[n+1]={0};
    while(m--){
        ll a,b,k;
        cin>>a>>b>>k;

        if(a>n+1 || b>n+1){
            continue;
        }
        if(a==b){
            arr[a]+=k;
            continue;
        }
        for(ll i=a;i<=b;i++){
            arr[i]+=k;
        }
    }
    ll temp=arr[0];
    
    /*for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    for(ll i=0;i<n+1;i++){
        temp=max(temp,arr[i]);
    }
    cout<<temp;
    return 0;
        
}
*/
