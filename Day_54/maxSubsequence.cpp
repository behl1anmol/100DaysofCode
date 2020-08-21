// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Custom sort function to sort the given string in 
// the order which maximises the final score 
int customSort(string s1, string s2) 
{ 
	// To store the count of occurrences 
	// of 'a' and 'b' in s1 
	int count_x1 = 0, count_y1 = 0; 
    //cout<<s1<<endl<<s2;
	// Count the number of occurrences 
	// of 'a' and 'b' in s1 
	for (int i = 0; i < s1.size(); i++) { 
		if (s1[i] == 'x') 
			count_x1++; 
		else
			count_y1++; 
	} 

	// To store the count of occurrences 
	// of 'a' and 'b' in s2 
	int count_x2 = 0, count_y2 = 0; 

	// Count the number of occurrences 
	// of 'a' and 'b' in s2 
	for (int i = 0; i < s2.size(); i++) { 
		if (s2[i] == 'x') 
			count_x2++; 
		else
			count_y2++; 
	} 

	// Since the number of subsequences 'ab' is 
	// more when s1 is placed before s2 we return 1 
	// so that s1 occurs before s2 
	// in the combined string 
	if (count_x1 * count_y2 > count_y1 * count_x2) { 
		return 1; 
	} 
	else { 
		return 0; 
	} 
} 


string concatenateStrings(string S[], int N) 
{ 

	// To store the concatenated string 
	string str = ""; 


	for (int i = 0; i < N; i++) 
		str += S[i]; 

	return str; 
} 

int getMaxScore(string S[], int N) 
{ 

    int i, j;
    string key;  
    for (i = 1; i < N; i++) 
    {  
        key = S[i];  
        j = i - 1;  
  
        while (j >= 0 && customSort(S[i],S[j])==1) 
        {  
            S[j + 1] = S[j];  
            j = j - 1;  
        }  
        S[j + 1] = key;  
    }  

	string combined_string = concatenateStrings(S, N); 

    for(int i=0;i<N;i++){
        cout<<S[i]<<" ";
    }


	int final_score = 0, count_x = 0; 
	for (int i = 0; i < combined_string.size(); i++) { 
		if (combined_string[i] == 'x') { 

			count_x++; 
		} 
		else { 

			final_score += count_x; 
		} 
	} 

	return final_score; 
} 

int main() 
{ 
	string S[] = { "yx","x","yyyx","xy" }; 
	int N = 4; 

	cout << getMaxScore(S, N); 

	return 0; 
} 
