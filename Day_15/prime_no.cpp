/*
T(n)=O(n^(1/2))
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int c=0;

        if(n<=1)    {cout<<"Not prime"; cout<<endl;continue;}
        if(n<=3)    {cout<<"Prime"; cout<<endl;continue;}

        if(n%2==0 || n%3==0){
            cout<<"Not prime\n";
            continue;
        }

        for(int i=5;i*i<=n;i=i+6){
            if(n%i==0||n%(i+2)==0){
                c++;
                break;
            }
        }     

        if(c==1)    cout<<"Not prime";
        else    cout<<"Prime";
        cout<<endl;
    }
    return 0;
}
