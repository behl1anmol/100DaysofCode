#pragma once
#include<iostream>
#include<queue>
using namespace std;

class token{
    public:
    int tokenSite;
    int tokenHolder;
    int *last;
    queue<int> q;

    token(int p);
};