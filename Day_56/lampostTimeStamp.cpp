#include<bits/stdc++.h>
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

int main()
{
int i,j,k,processOne[20],processTwo[20],eventOne,eventTwo,arr[20][20];
input(eventOne)>>eventTwo;
for(i=0;i<eventOne;i++) processOne[i]=i+1;
for(i=0;i<eventTwo;i++) processTwo[i]=i+1;

for(i=0;i<eventTwo;i++)
for(i=0;i<eventOne;i++)
{
for(j=0;j<eventTwo;j++)
input(arr[i][j]);
}

for(i=0;i<eventOne;i++)
{
	for(j=0;j<eventTwo;j++)
	{
		if(arr[i][j]==1)     
		{	processTwo[j]=max(processTwo[j],processOne[i]+1);
			for(k=j;k<eventTwo;k++)
			processTwo[k+1]=processTwo[k]+1;
		}
		if(arr[i][j]==-1)    
		{
			processOne[i]=max(processOne[i],processTwo[j]+1);
			for(k=i;k<eventOne;k++)
			processOne[k+1]=processOne[k]+1;
		}

	}
}
print("For Process 1: ");
for(i=0;i<eventOne;i++) print(processOne[i])<<" ";
nl;
print("For Process 2: ");
for(j=0;j<eventTwo;j++) print(processTwo[j])<<" ";

return 0 ;
}