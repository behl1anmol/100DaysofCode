#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int funcAlienHabitation(int arr[MAX][MAX],int n,int i, int j);

int funcAlienHabitation(int arr[MAX][MAX],int n,int i,int j){

    if(i<0 || j<0 || i>n-1 || j>n-1){
        return 0;
    }
    /*if(arr[i][j] == 0){
        return 0;
    }*/

    if((i==n-1 || j==n-1) && arr[i][j]==1){
        return 1 ;
    }
    if((i==n-1 || j==n-1) && arr[i][j]==0){
        return 0 ;
    }
    if(arr[i][j] == 1){
        int res = funcAlienHabitation(arr,n,i-1,j-1) + funcAlienHabitation(arr,n,i-1,j+1) + funcAlienHabitation(arr,n,i+1,j+1) + funcAlienHabitation(arr,n,i+1,j-1) + funcAlienHabitation(arr,n,i-1,j) + funcAlienHabitation(arr,n,i+1,j) + funcAlienHabitation(arr,n,i,j-1) + funcAlienHabitation(arr,n,i,j+1);
        if(res!=3 || res!=2){arr[i][j] = 0; return 0;}
        else return 1;
    }
 
    return 0;

}
int main(){
    int n;
    cin>>n;
    int arr[MAX][MAX];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    funcAlienHabitation(arr,n,0,0);

    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }


}