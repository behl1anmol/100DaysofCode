/*TLE*/
#include<bits/stdc++.h>

using namespace std;
int n;
vector<int>arr(200000);

int query(int l,int u){
    int temp=0;
    if(l==u){
        return arr[l-1];
    }
    vector<int> t(&arr[l-1],&arr[u]); 
    /*for(int i=0;i<t.size();i++){
        cout<<t[i]<<" ";
    }*/
    cout<<endl;
    for(int i=0;i<t.size();i++){

        if(i%2==0){
            temp=(t[i]*(i+1))+temp;
        }
        else{
            temp=temp-(t[i]*(i+1));
        }

    }
    return temp;

}
void update(int index,int val){

    arr[index-1]=val;

}
int main(){
    int t,temp=1;
    cin>>t;

    while(t--){
        int q;
        int sum=0;
        cin>>n>>q;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        while(q--){
            char c;
            cin>>c;
            int a,b;
            cin>>a>>b;
            if(c=='Q')
                sum=query(a,b)+sum;
            if(c=='U')
               update(a,b);
        }
        cout<<"Case#"<<temp<<": "<<sum;
        temp+=1;            
    }
}
