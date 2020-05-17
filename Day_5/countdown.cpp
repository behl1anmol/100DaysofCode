/*WA*/
#include<iostream>
#include<vector>

using namespace std;


int func_countdown(vector<int> arr,int k,int n){
    
    int temp=n;
    int count=0;
    
    for(int i=0;i<k;i++){
        
            if(temp==arr[i]){
                if(temp==1){
                    count+=1;
                    temp=n;
                }
                else{
                temp--;
                }
            }
            else{
                temp=n;
            }
    }
    return count;
}
int main(){
    int t;
    cin>>t;
    int c=1;
    
    while(t--){
        int k,n;
        cin>>k>>n;
        
        vector<int> arr(k);
        
        for(int i=0;i<k;i++){
            cin>>arr[i];
        }
        cout<<"Case #"<<c<<":"<<" "<<func_countdown(arr,k,n)<<endl;  
        c=c+1;
    }
    return 0;
}