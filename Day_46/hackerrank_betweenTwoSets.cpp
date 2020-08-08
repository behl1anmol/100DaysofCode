//T(n) = O(n(log(n)))
#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b){

return b?gcd(b,a%b):a;
}
int lcm(int a, int b){

return a*(b/gcd(a,b));
}
int main(){

int n,m;
cin>>n>>m;

int arr1[n];
int arr2[m];

for(int i=0;i<n;i++){
    cin>>arr1[i];
}
for(int i=0;i<m;i++){
    cin>>arr2[i];
}

int l = arr1[0];
int g = arr2[0];

for(int i=1;i<n;i++){
    l = lcm(l,arr1[i]); 
}


for(int i=1;i<m;i++){
    g = gcd(g,arr2[i]);
}

int count=0;
for(int i=l,j=2;i<=g;i=l*j,j++)
    if(g%i==0)count++;

cout<<count;
}
