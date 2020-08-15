#include<iostream>
#include<algorithm>
#include<fstream>
#define ll long long int
using namespace std;

int main(){
    std::ios_base::sync_with_stdio (false);
    cin.tie(NULL);
    
    //array containing vowel in text representation of number
    int vovel[101] = {2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 3, 2, 3, 4, 3, 3, 4, 4, 4, 1, 3, 2, 3, 3, 3, 2, 3, 3, 3, 1, 3, 2, 3, 3, 3, 2, 3, 3, 3, 1, 3, 2, 3, 3, 3, 2, 3, 3, 3, 1, 3, 2, 3, 3, 3, 2, 3, 3, 3, 1, 3, 2, 3, 3, 3, 2, 3, 3, 3, 2, 4, 3, 4, 4, 4, 3, 4, 4, 4, 2, 4, 3, 4, 4, 4, 3, 4, 4, 4, 2, 4, 3, 4, 4, 4, 3, 4, 4, 4, 2};
    //text representation of number
    string text[101] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine", "thirty", "thirty one", "thirty two", "thirty three", "thirty four", "thirty five", "thirty six", "thirty seven", "thirty eight", "thirty nine", "forty", "forty one", "forty two", "forty three", "forty four", "forty five", "forty six", "forty seven", "forty eight", "forty nine", "fifty", "fifty one", "fifty two", "fifty three", "fifty four", "fifty five", "fifty six", "fifty seven", "fifty eight", "fifty nine", "sixty", "sixty one", "sixty two", "sixty three", "sixty four", "sixty five", "sixty six", "sixty seven", "sixty eight", "sixty nine", "seventy", "seventy one", "seventy two", "seventy three", "seventy four", "seventy five", "seventy six", "seventy seven", "seventy eight", "seventy nine", "eighty", "eighty one", "eighty two", "eighty three", "eighty four", "eighty five", "eighty six", "eighty seven", "eighty eight", "eighty nine", "ninety", "ninety one", "ninety two", "ninety three", "ninety four", "ninety five", "ninety six", "ninety seven", "ninety eight", "ninety nine", "hundred"};
    int n;
    int arr[101];
    cin >> n;
    ll d = 0;

    //calculating total number of vowels in the given input
    for(int i=0;i<n;i++) {cin >> arr[i]; d+=(vovel[arr[i]]);}
    
    //Sorting the array
    sort(arr, arr+n);
    int ans=0;

     //Finding pairs using binary search
    for(int i=0;i<n;i++){
        if(binary_search(arr+i, arr+n, d-arr[i])){
            if(i>0 && arr[i]==arr[i-1]) continue;
            ans++;
        }
    }
    //printing answer in text
    cout << text[ans] << endl;
    return 0;
}