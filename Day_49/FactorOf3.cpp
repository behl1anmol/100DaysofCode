#include<bits/stdc++.h>
#define ll long long 
#define N 100000

using namespace std;

unordered_map<int,int> arrayFreq(int arr[], int n){

    unordered_map<int,int> temp;
    for(int i=0;i<n;i++){
        temp[arr[i]]++;
    }
    return temp;
}

pair<int,int> funcMaxEntry(unordered_map<int,int>frequencyHash){
     pair<int,int> maxFreq = make_pair(0,0);

    unordered_map<int, int>::iterator it;
    for(it = frequencyHash.begin(); it != frequencyHash.end(); it++){

        if(it->second > maxFreq.second){
            maxFreq = make_pair(it->first, it->second);
        }
    }
    return maxFreq;
}

int main(){

    std::ios_base::sync_with_stdio (false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        int size;
        cin>>size;

        int arrayInput[size];

        for(int i=0;i<size;i++){
            cin>>arrayInput[i];
        }
        unordered_map<int,int> frequencyHash = arrayFreq(arrayInput,size);
        
        pair<int,int>maxFreq = funcMaxEntry(frequencyHash);

        int checkCondition = (size+1)/3;
        if(maxFreq.second > checkCondition){
            cout<<"Yes";
        }
        else{
            cout<<"No";
        }
        cout<<"\n";
    }
    return 0;
}