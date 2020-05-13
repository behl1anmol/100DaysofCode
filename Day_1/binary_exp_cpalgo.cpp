/*Binary Exponentiation
        t(n)=(log n)
        */
#include<bits/stdc++.h>

using namespace std;

int binpow(int a,int n){
    if(n==0)
        return 1;

    int res=binpow(a,n/2);

    if(n%2!=0)
        return res*res*a;
    else
        return res*res;
            
}
int iter_binpow(int a,int n){
    int res=1;

    while(n>0){
        if(n&1){
            res=res*a;
        }
        a=a*a;
        n>>=1;
    }
    return res;
}
int main(){
    cout<<binpow(2,5)<<endl;
    cout<<iter_binpow(2,5);
}