//PIZZA CUTTING T(n) = O(n)

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        ll p;
        ll n;
        cin>>n;

        p = n*n + n + 2;
        p=p/2;
        cout<<p<<endl;
    }
    return 0;
}
