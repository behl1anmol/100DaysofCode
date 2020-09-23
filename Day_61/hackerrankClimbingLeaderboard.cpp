#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

ll n;
cin>>n;
stack<ll> s;

for(ll i=0;i<n;i++){
    ll temp;
    cin>>temp;
    if(s.empty() || s.top()!=temp) s.push(temp);
}
ll m;
cin>>m;
for(ll i=0;i<m;i++){
    ll temp;
    cin>>temp;
    while(!s.empty() && temp>=s.top()) s.pop();
    cout<<(s.size()+1)<<"\n";
}
return 0;
}