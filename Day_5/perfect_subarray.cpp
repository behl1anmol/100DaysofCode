/*TLE*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
int t,temp=1;
cin>>t;
while(t--){
int n,c=0;
cin>>n;
int a[n],presum[n+5];
for(int i=1;i<=n;i++) cin>>a[i];

presum[0]=0;
presum[1]=a[1];
for(int i=2;i<=n;i++)
{
presum[i]=presum[i-1]+a[i];
}

int k=0;
for(int i=0;i<n;i++)
{
k++;
for(int j=k;j<=n;j++)
{

int ans=presum[j]-presum[i];
int ans1=sqrt(ans);
if((ans1*ans1)==ans) c++;

}
}
cout<<"Case #"<<temp<<": "<<c<<endl;
temp=temp+1;
}
return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;
const int N = 5E3 + 5;
int a[N];
int main() {
    int t,test_set=1;
    cin>>t;
    while(t--){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> a[i];
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        double total = 0;
        for(int j = i; j < n; j ++) {
            total += a[j];
            double chkr = total;
            chkr = sqrt(chkr);
            if(chkr == floor(chkr))
                ans ++;
        }
    }
        cout<<"Case #"<<test_set<<": "<<ans<<endl;
        test_set+=1;
    }
    return 0;
}*/