#include<iostream>
#include "token.h"
#include "site.h"
#include "criticalSection.h"

void CS :: reqCS(int p,token* t,site* s[],int pid){
    
    int i,seqno;
    seqno = ++s[pid]->req[pid];

    if(s[pid]->isReq==true || s[pid]->isExec==true){
        cout<<" site: "<< pid<<"requested already"<<"\n\n";
        return;
    }
    s[pid]->isReq = true;

    if(t->tokenHolder == pid){
        s[pid]->isReq = false;
        s[pid]->isExec = true;
        cout<<"site :"<<pid<<"entering CS with token already"<<"\n\n";
        return;
    }
    if(t->tokenHolder != pid){
        for(int i=0;i<p;i++){
            if(i==pid) continue;
            s[i]->execRequest(t,pid,seqno);
        }
    }
    if(t->tokenHolder == pid){

        s[pid]->isReq=false;
        s[pid]->isExec=true;
        s[pid]->hasToken=true;

        cout<<"site:"<<pid<<"takes token and enters critical section"<<"\n";
        return;
    }
    else{
        cout<<"site:"<<t->tokenHolder<<"in CS and "<<pid<<"has placed his request"<<"\n";
    }
}
void CS :: relCS(token* t,site* s[],int pid){

    if(s[pid]->isExec!=true){
        cout<<"site: "<<"not in cs";
        return;
    }
    int i,sid;
    t->last[pid]=s[pid]->req[pid];
    s[pid]->isExec= false;
    cout<<"site:"<<pid<<"releases cs"<<"\n";

    if(!t->q.empty()){
        sid = t->q.front();
        t->q.pop();
        t->tokenSite = sid;
        s[pid]->hasToken = false;
        t->tokenHolder=sid;
        s[sid]->hasToken=true;
        s[sid]->isExec=true;
        s[sid]->isReq=false;
        cout<<"site:"<<"gets token and enters CS"<<"\n";
        return;
    }
    cout<<"site:"<<pid<<" has token"<<"\n\n";

}
