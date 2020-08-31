#include "token.h"

token::token(int p){
    tokenSite = 0;
    last = new int[p];

    for(int i=0;i<p;i++){
        last[i] = 0;
    }
}