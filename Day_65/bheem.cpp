#include<bits/stdc++.h>
using namespace std;

vector<int>solve(int A,int B){

    vector<int> v(A);

    v[B-1] = A;
    int temp=1;

    for(int i=0;i<A;i++){
        if(i == B-1) continue;
        v[i] = temp++;
    }

    return v;  
}
int main(){
    int a,b;cin>>a>>b;

    vector<int> ans = solve(a,b);

    for(int i=0;i<a;i++){
        cout<<ans[i]<<" ";
    }
}