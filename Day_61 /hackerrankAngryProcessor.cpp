#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,threshold;
        cin>>n>>threshold;
        int count=0;

        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            if(temp<=0) count++;
        }
        if(count>=threshold)
            cout<<"NO";
        else
            cout<<"YES";
        cout<<"\n";
    }
    return 0;
}