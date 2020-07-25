//HEAP SORT 
//T(n) = O(n log(n))
#include<bits/stdc++.h>
using namespace std;

void maxHeapify(int arr[], int n, int i){
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;
    if(left < n && arr[left]>arr[largest])
        largest = left;
    if(right < n && arr[right] > arr[largest])
        largest = right;
    if(largest != i){
        int t= arr[i];
        arr[i] = arr[largest];
        arr[largest] = t;

    maxHeapify(arr, n , largest);
    }
}

void buildMaxHeap(int arr[],int n){


for(int i=n/2-1 ;i>=0;i--){
        maxHeapify(arr,n,i);
}
}

void heapSort(int arr[], int n){

for(int i=n-1;i>0;i--){
    int t = arr[0];
    arr[0] = arr[i];
    arr[i] = t;
    maxHeapify(arr,i,0);
}
}

int main(){
int arr[] = {9,6,5,0,8,2,1,3};
int n = sizeof(arr)/sizeof(arr[0]);
buildMaxHeap(arr,n);
cout<<"HEAP IS: ";
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
heapSort(arr,n);
cout<<"Sorted Array is:";
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}

return 0;
}
