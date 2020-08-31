#pragma once         
#include "site.h"
#include "token.h"
using namespace std;

class CS{
    public:
    void reqCS(int p,token* t,site* s[],int pid);
    void relCS(token* t,site* s[],int pid);
};