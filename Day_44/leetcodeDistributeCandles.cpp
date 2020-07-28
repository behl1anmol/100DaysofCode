#include<bits/stdc++.h>
using namespace std;

vector<int> distributeCandies(int candies, int num_people) {
vector<int> arr(num_people);

int k=0;
while(candies>0){
    arr[k%num_people] += min(candies, k+1);
    candies = candies-(k+1);
    k=k+1;
    }
return arr;
}
int main(){

    vector<int> arr = distributeCandies(10,3);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}