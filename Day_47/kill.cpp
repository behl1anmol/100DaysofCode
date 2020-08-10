#include<bits/stdc++.h>

using namespace std;

void preorder(int arr[],int n,int pos){

    if(pos>n){
        return;
    }
    arr[pos]=-1;
    preorder(arr,n,(2*pos));
    preorder(arr,n,(2*pos+1));
}
int main(){
    int n,k;

    cin>>n;
    cin>>k;

    int arr[k];

    int tree[n+1];
    for(int i=1;i<n+1;i++){
        tree[i]=i;
    }

    for(int i=0;i<k;i++){
        cin>>arr[i];
    }

    for(int i=0;i<k;i++){
        
        int pos = arr[i];
        preorder(tree,n,pos);
    }
    int flag=0;
    for(int i=1;i<n+1;i++){  
        if(tree[i]!=-1){
        flag=1;
        cout<<tree[i]<<" ";
        }
    }
    if(flag==0){
        cout<<"0";
    }
}