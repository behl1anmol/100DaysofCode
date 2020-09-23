#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int funcAlienHabitation(int arr[MAX][MAX],int n,int i, int j);

int neighbour(int arr[MAX][MAX],int v[MAX][MAX],int n,int i,int j){
        int count=0;
        if (i > 0 && arr[i - 1][j] == 1 && v[i-1][j]==false) 
			count++; 
		if (j > 0 && arr[i][j - 1] == 1 && v[i][j-1]==false) 
			count++; 
		if (i > 0 && j > 0 && arr[i - 1][j - 1] == 1 && v[i-1][j-1]==false) 
			count++; 
		if (i < n - 1 && arr[i + 1][j] == 1 && v[i+1][j]==false) 
			count++; 
		if (j < n - 1 && arr[i][j + 1] == 1 && v[i][j+1]==false)  
			count++; 
		if (i < n - 1 && j < n - 1 && arr[i + 1][j + 1] == 1 && v[i+1][j+1]==false) 
			count++; 
		if (i < n - 1 && j > 0 && arr[i + 1][j - 1] == 1 && v[i+1][j-1]==false) 
			count++; 
		if (i > 0 && j < n - 1 && arr[i - 1][j + 1] == 1 && v[i-1][j+1]==false) 
			count++; 

}
int funcAlienHabitation(int arr[MAX][MAX],int v[MAX][MAX],int n,int i,int j){

    if(arr[i][j]==1){
        int count = neighbour(arr,v,n,i,j);
        int result = 8 - count;

        
    }

    return 0;

}
int main(){
    int n;
    cin>>n;
    int arr[MAX][MAX];
    bool v[MAX][MAX];
    fill(&v[0][0],&v[0][0]+sizeof(v),false);
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