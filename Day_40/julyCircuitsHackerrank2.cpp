
#include<bits/stdc++.h>
using namespace std;

int getProduct(int n){
    int product =1;

    while(n!=0){
        if((n%10) == 1){
            product = 0;
            return product;
        }
        product = product * (n%10);
        n = n/10;
    }
    return product;
}

int main(){

    int n, count=0;
    cin>>n;

    if(n>100){
        cout<<count;
        return 0;
    }

    for(int i=1;i<=1000000; i++){
        int product = 1;
        product = getProduct(i);
        if(product == n){
            count++;
        }
    }
    cout<<count;
}