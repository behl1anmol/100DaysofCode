#include<bits/stdc++.h>
using namespace std;
#define print(n) cout<<n
int main(){

    int n,r;
    cin>>n>>r;

    if(r==1){
        print(0);
        return 0;
    }
    if(n%2==0 && r==n-1){
        print(1);
        return 0;
    }
    int front = 1+ ((r-2)/2);
    int back = (n-r)/2;

    if(front>back) print(back);
    else print(front);

    return 0;
}