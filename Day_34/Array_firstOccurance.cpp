#include<bits/stdc++.h>

using namespace std;

int firstOccurance(vector<int>v, int n, int x){

    for(int i=0;i<n;i++){
        if(v[i]==x)
            return i;
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

    cout<<"Index is:"<<firstOccurance(v,n,x);

    return 0;

}