#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll poss[20]; //possibilities array
ll bit1[20]; //hash for bit 1
ll bit0[20]; //hash for bit 2
ll ans=0;
ll maxLength=0;


//find bits 1 and 0 in a number
void findbits(ll arr[], int n){
    for(int i=0;i<n;i++){
        int num = arr[i];
        ll counter = 0;
        while(num>0){
            counter++;
            if(num&1) bit1[i]++;
            else bit0[i]++;
            num = num >> 1;
        }
        bit0[i]+= maxLength - counter;
    }
}

//printing the array of possibility
void printArray(int n){
    for(int i=0;i<n;i++){
        cout << poss[i];
    }
    cout << endl;
}

//after finding possibility this function checks if number of 1 and 0 equal in set
void compute(int n){
    ll one=0, zero=0;
    for(int i=0;i<n;i++){
        if(poss[i]) {one+=bit1[i]; zero+=bit0[i];}
    }
    if(one == zero && one!=0) {ans++;}
}

//find every possible combination
void possibilities(int n, int i){
    if(i==n){
        compute(n);
        return;
    }
    poss[i]=0;
    possibilities(n, i+1);
    poss[i]=1;
    possibilities(n, i+1);
}

//convert the answer in binary
string convert(){
    string s= "";
    while(ans>0){
        if(ans&1) s='1'+s;
        else s='0'+s;
        ans = ans >> 1;
    }
    while((unsigned long long)maxLength>s.size()){
        s= '0' + s;
    }
    return s;
}

int main(){
    int n;
    cin >> n;
    ll arr[20];
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        //number of bits to reprsent largest element in array
        maxLength = max(maxLength, max(0LL, (ll)log2(arr[i])));
    }
    maxLength++;
    findbits(arr, n);
    possibilities(n, 0);
    cout << convert() << endl;
}