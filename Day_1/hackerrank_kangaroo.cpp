//https://www.hackerrank.com/challenges/kangaroo/problem

#include<iostream>
#include<vector>

using namespace std;

bool fun_naive_kangaroo(int x1,int v1,int x2,int v2){
int k=10000;
if(v2>v1){
    return false;
}
while(k--){
x1=x1+v1;
x2=x2+v2;
if(x1==x2){
    break;
}
}
if(x1==x2){
    return true;
}
return false;
}

bool fun_kangaroo(int x1,int v1,int x2,int v2){
    if(v2>=v1)
        return false;
    else if((x2-x1)%(v2-v1)==0)
        return true;
    return false;           
}
int main(){
int x1,v1,x2,v2;
cin>>x1>>v1>>x2>>v2;

if(fun_kangaroo(x1,v1,x2,v2)==true){
    cout<<"YES";
}
else{
    cout<<"NO";
}
return 0;
}


