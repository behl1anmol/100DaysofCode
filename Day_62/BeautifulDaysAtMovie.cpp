#include<bits/stdc++.h>
using namespace std;

int reverse(int n){
    int rem;
    while(n!=0){
        rem = rem + (10*(n%10));
        n = n/10;
    }
    return rem;
}
int main(){

int a,b,k;
cin>>a>>b>>k;
int count=0;

for(int i=a;i<=b;i++){
    int rev = reverse(i);

    if(abs(a-rev)%k==0){
        //cout<<a<<endl;
        count++;
    }

}
cout<<count;
return 0;
}