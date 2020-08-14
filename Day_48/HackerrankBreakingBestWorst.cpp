/*Breaking Best and Worst Records
T(n) = O(n)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];

    int i;

    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int min=a[0],max=a[0],min_count=0,max_count=0;

    for(i=1;i<n;i++){
        if(min>a[i]){
            min=a[i];
            min_count++;
        }
        if(max<a[i]){
            max=a[i];
            max_count++;
        }
    }
    cout<<max_count<<" "<<min_count;
    return 0;
}