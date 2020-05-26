/* sparse array hackerrank
    T(n)=O(nlog(n))
*/
#include<iostream>
#include<unordered_map>

using namespace std;

int main(){

    unordered_map<string, int> map;
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;

        if(map.find(temp)==map.end()){
            map[temp]=1;
        }
        else
            map[temp]+=1;
    }

    int k;
    cin>>k;

    for(int i=0;i<k;i++){
        string temp;
        cin>>temp;
        
        unordered_map<string, int>::iterator got=map.find(temp);

        if(got == map.end()){
            cout<<0<<endl;
        }
        else
            cout<<got->second<<endl;
    }
    return 0;

}