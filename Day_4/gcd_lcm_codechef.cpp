/*
Contest Code:PRACTICE Problem Code:FLOW016
*/

#include <iostream>
using namespace std;

long long gcd(long long a,long long b){
    
    return b? gcd(b,a % b) : a;
    
}
long long lcm(long long a,long long b){
    
    return a / gcd(a,b) *b;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
        cout<<gcd(a,b)<<" "<<lcm(a,b)<<endl;
    }
	return 0;
}
