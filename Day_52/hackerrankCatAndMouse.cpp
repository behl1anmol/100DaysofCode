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


using namespace std;

int main(){
    int t,a,b,m;
    input(t);

    while(t--){
        input(a)>>b>>m;
        int catA = abs(m-a);
        int catB = abs(m-b);

        (catA<catB)?printl("Cat A"):catA==catB?printl("Mouse C"):printl("Cat B") ;
    }
    return 0;
}