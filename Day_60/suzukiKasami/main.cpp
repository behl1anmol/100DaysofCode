#include<iostream>
#include "token.h"
#include "site.h"
#include "criticalSection.h"
#include<string>
#include<queue>

using namespace std;

void state(int p,token* t,site *s[]){
    int i,j,k=0;
    queue<int>temp;
    cout<<"TOKEN STATE"<<"\n\n";
    cout<<"Token Holder:"<<t->tokenHolder<<"\n";
    cout<<"Token Req Queue:";

    if(t->q.empty()){
        cout<<"Empty"<<"\n";
        j=0;
    }
    else{
        j=t->q.size();
    }
    while(k<j){
        i=t->q.front();
        t->q.pop();
        t->q.push(i);
        cout<<i<<" ";
        k++;
    }
    cout<<endl;
    cout<<"No. of times token held:"<<endl;

    for(i=0;i<p;i++){
        cout<<t->last[i]<<"\t";
    }
    cout<<"\n\n";

    cout<<"Site array:"<<"\n";

    for(i=0;i<p;i++){
        cout<<"S"<<i<<":"<<"\t";

        for(j=0;j<p;j++){
            cout<<s[i]->req[i]<<"\t";
        }
        cout<<"\n";
    }
}

int main(){
    int i,j,tme,pid;
    int p;
    string str;

    cout<<"Enter processes:"<<"\n";
    cin>>p;

    CS* c = new CS();
    token* t = new token(p);
    site** s = new site*[p];

    for(int i=0;i<p;i++){
        s[i] = new site(p);
    }
    t->tokenHolder=0;
    s[0]->hasToken=true;
    tme=0;
    cout<<"No of sites:"<<p<<"\n\n";
    cout<<"state initially:"<<"\n";
    state(p,t,s);

    cout<<"enter events in the format: \n ->REQUEST <pid> //for request\n ->RELEASE <pid> //for release\n->EXIT //to exit\n\n";
    while(str!="EXIT"){
        	cin >> str;

		if (str == "REQUEST")
		{
			cin >> pid;
			cout << endl;
			cout << "EVENT : " << str << " " << pid << endl << endl;
			c->reqCS(p,t,s,pid);
			state(p,t,s);
			cout << "\n";
		}
		else if (str == "RELEASE")
		{
			cin >> pid;
			cout << endl;
			cout << "EVENT :" << str << " " << pid << endl << endl;
			c->relCS(t,s,pid);
			state(p,t,s);
			cout <<"\n";
		}
	}

    return 0;

}
