/*
gcd(a,b)={a    if b==0,

           gcd(b,a mod b), otherwise.
           }
           

           T(n)=O(logmin(a,b))
           atmost n-2 recurssive calls
*/

#include<bits/stdc++.h>
using namespace std;


void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}


int eucledian_algo(int a,int b){

return b?eucledian_algo(b,a%b):a;
}
int iterative_eucledian(int a,int b){
    while(b!=0){
        a=a%b;
        swap(&a,&b);
    }
    return a;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<eucledian_algo(a,b)<<endl<<iterative_eucledian(a,b);
    return 0;
}