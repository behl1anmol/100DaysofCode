//Sliding Window T(n) = O(n)
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int> v(n);
    int i,j;

    for(i=0;i<n;i++){
        cin>>v[i];
    }
    int m,d;
    cin>>d>>m;
    int count=0;

    for(auto it=v.cbegin();it!=v.cend();it++){
        if(d==accumulate(it,it+m,0))
            count++;
    }
    cout<<count;
    return 0;
}