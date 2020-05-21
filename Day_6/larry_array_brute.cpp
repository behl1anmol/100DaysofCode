/*
hackerrank larry array T(N)=O(N^2)
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> arr(n);

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int inv=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j]){
                    inv++;
                }
            }
        }

            if(inv%2==0){
                cout<<"YES";            
            }
            else{
                cout<<"NO";
            }
            cout<<endl;

    
    }
return 0;
}