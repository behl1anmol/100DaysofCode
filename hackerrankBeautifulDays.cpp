#include<bits/stdc++.h>
using namespace std;

int reverse(int n){
    int rem=0,rev=0;
    while(n!=0){
        rem = n%10;
        rev = (rev*10)+rem;
        n = n/10;
    }
    return rev;
}
int main(){

int a,b,k;
cin>>a>>b>>k;
int count=0;

for(int i=a;i<=b;i++){
    int rev = reverse(i);

    if(abs(i-rev)%k==0){
        count++;
    }

}
cout<<count;
return 0;
}
