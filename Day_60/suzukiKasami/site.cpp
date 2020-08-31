#include "site.h"

site::site(int p){
    req = new int[p];
    isReq = false;
    isExec = false;
    hasToken = false;

    for(int i=0;i<p;i++){
        req[i] = 0;
    }
}

void site::execRequest(token* t,int pid,int seqno){

    req[pid] = max(req[pid],seqno);

    if(hasToken==true){
        if(isExec==false && t->last[pid]+1 == req[pid]){
            hasToken = false;
            t->tokenHolder = pid;
        }
    else if(t->last[pid]+1 == req[pid]){
        t->q.push(pid);
        }
    }
}
