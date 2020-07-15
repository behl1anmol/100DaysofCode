#include<bits/stdc++.h>

using namespace std;

vector<int> insertion_sort(vector<int> a){
    int n=a.size();

    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(a[j]>key && j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;    
    }
return a;
}    
int main(){

    vector<int>v=(insertion_sort(vector<int> {5,4,3,2,1}));
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}