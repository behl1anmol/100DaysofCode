/*using graph
https://www.geeksforgeeks.org/number-of-transpositions-in-a-permutation/
Time Complexity : O(n)
Auxiliary space : O(n)
*/
#include<bits/stdc++.h>

using namespace std;

#define N 1000

vector<int> visited(N);

vector<int> goesto(N);

int dfs(int i){
    if(visited[i]==0)
        return 0;

    visited[i]=1;
    int x=dfs(goesto[i]);
    return (x+1);  
}
int func_permutations(vector<int> arr,int n){
  
  for(int i=0;i<=n;i++){
      visited[i]=0;
  }
  for(int i=1;i<n;i++)
    goesto[arr[i]]= i + 1;

    int inversion=0;

    for(int i=0;i<n;i++){
        if(visited[i==0]){
            int ans=dfs(i);
            inversion+=ans;
        }
    }
    return inversion;
}
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

        int inversion=func_permutations(arr,n);

        if(inversion % 2 == 0){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }

    }
}