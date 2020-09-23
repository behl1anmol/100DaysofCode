#include<bits/stdc++.h>
#define MAX 6
using namespace std;

int main(){

    string s;
    getline(cin,s);
    istringstream ss(s);
    int sum=0,num;
    
    queue<int> q;
    queue<int>temp;
    while(ss>>num){
        while(num>6){
            num=num-MAX;
            q.push(MAX);
        }
        q.push(num);
    }
    while(!q.empty()){
        if(temp.size()==2){
            cout<<endl;
            sum=0;
            while(!temp.empty()){
                int n = temp.front();
                sum=sum + n;
                if(sum==MAX){
                    cout<<n<<endl;
                    sum=0;
                    temp.pop();
                    continue;
                }
                if(sum>MAX){
                    cout<<n<<" ";
                    temp.pop();
                    continue;
                }
                cout<<n;
                temp.pop();
            }
        }
        num = q.front();
        sum = sum + num;

        if(sum>MAX){
            temp.push(num);
            sum=sum-num;
            q.pop();
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