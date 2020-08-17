#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin>>n;
    vector<int>v(n);
    
    for(int i=0;i<n;i++){
    cin>>v[i];    
    }
    
    double ans=0.0;
    
    for(double i=1;i<=n;i++){
        ans = ans + 1/i ;
    }
    cout << setprecision(6) << fixed; 

    cout<<ans;
    return 0;
}