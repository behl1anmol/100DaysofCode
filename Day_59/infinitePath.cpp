#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    assert (T>=1 && T<=10);
    while(T--)
    {
        string S;
        cin>>S;
        assert (S.length()>=1 && S.length()<=100000);
        int max_1=0,max_2=0;
        int cur=0;
        for (int i=0;i<S.length();i++)
        {
            if(S[i]!='A')
                cur++;
            else
                cur--;
            max_1=max(max_1,cur);
        }
        cur=0;
        for (int i=0;i<S.length();i++)
        {
            if(S[i]!='C')
                cur++;
            else
                cur--;
            max_2=max(max_2,cur);
        }
        cout<<max(max_1,max_2)<<endl;
    }
    return 0;
}