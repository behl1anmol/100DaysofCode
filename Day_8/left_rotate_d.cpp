/* left_rotate 
t(n)=o(n)
s(n)=o(d)
hackerrank
*/
#include<iostream>
#include<vector>

using namespace std;

void left_rotate(int v[],int n,int d){

    int temp[d];

    for(int i=0;i<d;i++)
        temp[i]=v[i];

    for(int i=0;i<n-d;i++)
        v[i]=v[i+d];

    for(int i=0;i<d;i++)
        v[n-d+i]=temp[i];         
}
int main(){

    int n;
    cin>>n;

    int d;
    cin>>d;
    int v[n];

    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    left_rotate(v,n,d);

    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
