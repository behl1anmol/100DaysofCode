#pragma once
#include <string> 
#include "token.h"
using namespace std;

class site{
    public:
    int *req;
    bool isExec;
    bool isReq;
    bool hasToken;

    site(int p);

    void execRequest(token* t,int pid,int seqno);
};
