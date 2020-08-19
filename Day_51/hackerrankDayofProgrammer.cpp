//T(n) = O(1)
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    if(n==1918){
        cout<<"26.09.1918";
        return 0;
    }

    if(n%4==0  && (n<1918 || n%400==0 || n%100!=0)){
        cout<<"12.09."<<n;
    }
    else{
        cout<<"13.09."<<n;
    }
    return 0;
}
