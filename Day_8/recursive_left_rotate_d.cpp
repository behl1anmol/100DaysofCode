#include<iostream>
#include<vector>

using namespace std;

void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}
vector<int> func_reverse(vector<int> arr,int s,int d){
  int high=d;
  int low=s;

  while(low<high){
    swap(&arr[low],&arr[high]);
    low++;
    high--;
  }
  return arr;
}

/*T(n)=O(n) , S(n)=O(1)*/
vector<int> reversal_algo(vector<int> arr,int n,int d){
  arr=func_reverse(arr,0,d-1);
  arr=func_reverse(arr,d,n-1);
  arr=func_reverse(arr,0,n-1);

  return arr;
}

int main(){
  int n,d;
  cin>>n>>d;
  vector<int> arr(n);

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  arr=reversal_algo(arr,n,d);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}
