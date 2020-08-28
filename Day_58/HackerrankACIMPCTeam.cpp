/* works only for smaller inputs*/

#include <bits/stdc++.h>
#define popCount(x) __builtin_popcount(x)
#define ll long long
using namespace std;


int main(){

    int q,n;
    cin>>q>>n;
    vector<int> v(q);
    for(int i=0;i<q;i++){
        string str;
        cin>>str;
        int c = stoul(str,0,2);
        v[i] = c;
    }
    int maxElement=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            maxElement = max(maxElement,popCount((v[i]|v[j])));
        }
    }
    int count =0;
    for(int i=0;i<q;i++){
        for(int j=0;j<q;j++){
            if(popCount((v[i]|v[j])) == maxElement) count++;
        }
    }
    cout<<maxElement<<endl<<count;
}