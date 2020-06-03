#include<bits/stdc++.h>

using namespace std;

void max_possible_value(int n , int k)
{
    cout << ((((k - 1) | k) > n && k % 2 == 0) ? k - 2 : k - 1) << std::endl;
}
int main(){
    int t;
    cin>>t;

    while(t--){
        int a,b;
        cin>>a;
        cin>>b;
        max_possible_value(a,b);
    }
    return 0;
}
