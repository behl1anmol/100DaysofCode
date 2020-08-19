#include<bits/stdc++.h>


////////////////////////////////////////////Macro Definitions////////////////////////////
#define sync() ios_base::sync_with_stdio(false)
#define tie() cin.tie(NULL)
#define pre(n) precision(n)
#define fix fixed
#define print(n) cout<<n
#define printl(n) cout<<n<<"\n"
#define prints(n) cout<<n<<" "
#define nl cout<<"\n"
#define input(n) cin>>n
#define fr(i,n) for(int i=0;i<n;i++)
#define frv(i,a,n) for(i=a;i<n;i++)
#define popCount(x) __builtin_popcount(x)
#define fa(n) for(auto &i:v)

//ternary operator
#define ter(x) x ? True:False

using namespace std;

int main(){
    int n;
    input(n);

    string s;
    input(s);

    int seaLevel=0;
    int valley=0;

    fr(i,n){
        if(s[i] == 'U') seaLevel++;
        if(s[i] == 'D') seaLevel--;
        if(seaLevel==0 && s[i]=='U') valley++;
    }  
    print(valley);
    return 0;
}
