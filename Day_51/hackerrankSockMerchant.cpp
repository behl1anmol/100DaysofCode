#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    unordered_map<int,int>m;

    for (int i=0;i<n;i++){
        int temp;
        cin>>temp;

        m[temp]++;
    }

    int count=0;

    unordered_map<int,int>::iterator it;

    for(it=m.begin();it!=m.end();it++){
        count += (it->second/2);
    }
    cout<<count;
    return 0;
}