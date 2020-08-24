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
#define frv(i,a,n) for(int i=a;i<n;i++)
#define popCount(x) __builtin_popcount(x)
#define fa(n) for(auto &i:v)

//ternary operator
#define ter(x) x ? True:False

//iterator
#define iterb(n) n.begin()
#define itere(n) n.end() 
#define fir(T) T->first()
#define sec(T) T->second()

//vector
#define vec(T) vector<T>
#define nvec(T) vector<vector<T>> 
#define fa(n) for(auto &i:v)
#define pb(v,n) v.push_back(n)

//unordered map
#define umap(T,N) unordered_map<T,N>

//pair
#define pr(T,N) pair<int,int>
#define mp(M,N) make_pair(T,N)

//set
#define st(T) set<T>

using namespace std;

int main(){
    int t;
    input(t);

   while(t--){
       int n,k;
       cin>>n>>k;

        vector<int> v(n);
       for(int i=0;i<n;i++){
           cin>>v[i];
       }
       int sum=0,rt=0,flag=0;

       int vs = accumulate(v.begin(),v.end(),0);


        if((n==1 && v[0]<k) || vs<k){
            cout<<1<<endl;continue;
        }
        if((n==1 && v[0] >k) ){
            cout<<-1<<endl;continue;
        }
       for(int i=0;i<n;i++){
           if(sum + v[i] <= k ){
               sum = sum + v[i];
               continue;
           }
           rt+=1;
           if(v[i]>k){
               flag=1;
               break;
           }
           else{
               sum=v[i];
           }
       }
       if(flag==1) cout<<-1<<endl;
       else cout<<rt+1<<endl;
   }

    return 0;
}