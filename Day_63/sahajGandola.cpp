#include<bits/stdc++.h>
#define MAX 6
using namespace std;

int main(){

    string s;
    getline(cin,s);
    istringstream ss(s);
    int sum=0,num;
    
    queue<int> q;
    while(ss>>num){
        while(num>6){
            num=num-MAX;
            q.push(MAX);
        }
        q.push(num);
    }
    while(!q.empty()){
        num = q.front();
        sum = sum + num;

        if(sum>MAX){
            cout<<"\n";
            //q.pop();
            sum=0;
            continue;
        }
        else if(sum==MAX){
            cout<<num<<"\n";
            q.pop();
            sum=0;
            continue;
        }
        cout<<num<<" ";
        q.pop();
    }
    return 0;
}