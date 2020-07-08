#include<bits/stdc++.h>

using namespace std;

int firstOccurance_BinarySearch(vector<int>v, int n, int x){

    int lb=0;
    int ub=n-1;

    while(ub>lb){
        int mid= (lb+ub)/2;

        if(v[mid]==x)
            return mid;

        if(v[mid]>x)
            ub=mid-1;

        if(v[mid]<x)
            lb=mid+1;        

    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int x;
    cin>>x;

    cout<<"Index is:"<<firstOccurance_BinarySearch(v,n,x);

    return 0;

}