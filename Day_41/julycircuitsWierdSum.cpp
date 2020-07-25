#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
	int n, k;
	ll  m;
	cin>>n>>k>>m;
    ll arr[n+1];

	for(int i=1;i<n+1;i++){
		cin>>arr[i];
	}
	ll sum = 0;
	for(int i=1;i<n+1;i++){
		int l = 1;
        ll mod = (l%m);
        l=l+1;
		ll temp = arr[i]*mod;
        if((k+i)>n){
            break;
        }
		for(int j=i+1;j<k+i;j++){
            mod = (l % m);
            l=l+1;
			temp = temp + arr[j] * mod; 
		}
		sum = max(sum,temp);
	}
	cout<<sum;
}