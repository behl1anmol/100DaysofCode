#include<bits/stdc++.h>
using namespace std;

int getCount(int temp){
    int count = 0;
    while(temp){
        count++;
        temp/=2;
    }
    return count;
}
bool funcCheck(vector<int> temp_v, int maxElement){
	int sum = 0; 
    for(int i:  temp_v){
        sum += __builtin_popcount(i);
        } 
	return (unsigned long int)(sum * 2) == maxElement * temp_v.size();
}
int main()
{
    int n; 
    cin >> n;
    vector<int> v(n); 
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
 
    int maxElement = 0,answer = 0; 
    for(int i: v){ 
        maxElement = max(maxElement, getCount(i));
    }
    for(int k = 1; k < (1 << n);  k++){
    	vector<int> calculate;
    	for(int j=0; j< n; j++){
    		if((k >> j) & 1) calculate.emplace_back(v[j]);
    	}
    	auto character = funcCheck(calculate,maxElement);
    	answer += character;
    }	
    answer %= (1 << maxElement);
    string s = bitset<64>(answer).to_string();
    string newS;
    for(int i= s.size()-1,itr = maxElement;i>=0 and itr;i--,itr--){
    	newS += s[i];
    }
    reverse(newS.begin(),newS.end());
    cout << newS;
 
}