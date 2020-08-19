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
//vector
#define vec(T) vector<T>
#define nvec(T) vector<vector<T>> 
#define fa(n) for(auto &i:v)
#define pb(v,n) v.push_back(n)
using namespace std;

int main(){

    int maxCost, key, usb;
    cin>>maxCost>>key>>usb;

    vec(int) k(key);
    vec(int) u(usb);

    fr(i,key) input(k[i]);
    fr(i,usb) input(u[i]);

    int maxSpend=0;

    fr(i,key){
        fr(j,usb){
            if((k[i] +u[j]) <= maxCost)
                maxSpend = max((k[i] + u[j]),maxSpend);
        }
    }

    if(maxSpend==0) print(-1);
    else print(maxSpend);
    return 0;
}