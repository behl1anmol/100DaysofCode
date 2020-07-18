#include<bits/stdc++.h>

using namespace std;

int bitScore(int N) {
 int a, b, c, l, s;
 int score;

 a = N%10; 
 N/=10;
 b = N%10; 
 N/=10;
 c = N%10; 
 N/=10;

 l = (a>b)?a:b;
 l = (c>l)?c:l;
 s = (a<b)?a:b;
 s = (c<s)?c:s;

 s = l*11 + s*7;

 s = s % 100;
 return s;
}

int findPairs (int scoreArr[], int N) {
 int s[10], calculatePairs = 0, mostSigBit;

 for(int i=0; i<10; i++) {
  s[i] = 0;
 }

 for(int i=0; i<N; i=i+2) {
  mostSigBit = scoreArr[i] / 10;
        for(int j =i+2; j<N; j=j+2){
            if(mostSigBit == scoreArr[j]/10){
                if(s[mostSigBit] < 2) {
                s[mostSigBit]++;
          }
            }
        }
  
 }
    
    for(int i=1; i<N; i=i+2) {
  mostSigBit = scoreArr[i] / 10;
  for(int j =i+2; j<N; j=j+2){
            if(mostSigBit == scoreArr[j]/10){
                if(s[mostSigBit] < 2) {
                s[mostSigBit]++;
          }
            }
        }
 }

 for(int i=0; i<10; i++) {
  calculatePairs = calculatePairs + s[i];
 }

 return calculatePairs;
}


int main() {

 int N, i;
 int arr[501];
 int scoreArr[501];
 int calculatePairs;
 cin>>N;

 for(i=0; i<N; i++) {
  cin>>arr[i];
 }

 for(i=0; i<N; i++) {
  scoreArr[i] = bitScore(arr[i]);
 }

 calculatePairs = findPairs(scoreArr, N);
 cout<<calculatePairs;

 return 0;
}