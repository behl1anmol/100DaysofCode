#include <iostream>
#include <fstream>

using namespace std;

bool in[51];
bool out[51];
bool p[51][51];

void pAns(int n, fstream& coutf){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(p[i][j])
                coutf << "Y";
            else
                coutf << "N";
        }
        coutf << endl;
    }
}

int main(){
    fstream cinf;
    cinf.open("travel_restrictions_input.txt");
    fstream coutf;
    coutf.open("output.txt", fstream::out);
    int t;
    cinf >> t;
    int count = 0;
    while(t--){
        count++;
        int n;
        cinf >> n;
        char ch;
        for(int i=1;i<=n;i++) fill(p[i], p[i]+n+1, false);
        fill(in, in+n+1, false);
        fill(out, out+n+1, false);
        for(int i=1;i<=n;i++){
            cinf >> ch;
            if(ch=='Y') in[i]=true;
            else in[i]=false;
        }
        for(int i=1;i<=n;i++){
            cinf >> ch;
            if(ch=='Y') out[i]=true;
            else out[i]=false;
        }
        for(int i=1;i<=n;i++){
            int curr = i;
            p[i][i]=true;
            while(curr!=n && out[curr] && in[curr+1]) {p[i][curr+1]=true; curr++;}
            curr=i;
            while(curr!=1 && out[curr] && in[curr-1]) {p[i][curr-1]=true; curr--;}
        }
        coutf << "Case #" << count << ": " << endl; 
        pAns(n, coutf);
    }
    return 0;
}