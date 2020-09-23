//#include "disappearingact.h"
#include<iostream>
#include <vector>
using namespace std;

vector<int> minimalMoves(vector<vector<int>> initialCameraPositionList){
    vector<int> optimalAnswer;
    int row = initialCameraPositionList.size();
    int column = initialCameraPositionList[0].size();
    int initial = row-1;
    //optimalAnswer.push_back(0);
    while(initial!=0){
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(initialCameraPositionList[i][j]==1 && j==column-1){
                    initialCameraPositionList[i][0]=1;
                    initialCameraPositionList[i][j]=0;
                    break;
                }
                else{
                    initialCameraPositionList[i][j] = 0;
                    initialCameraPositionList[i][j+1] = 1;
                    break;
                }
            }
        }
        if(initialCameraPositionList[initial-1][0] == 0){ initial--; optimalAnswer.push_back(1);}
        else if(initialCameraPositionList[initial][0] == 1){ optimalAnswer.clear(); break;}
        else optimalAnswer.push_back(0);
    }
    return optimalAnswer;
}

int main(){
    vector<vector<int>> initial = {{0,0,1,0},{0,1,0,0},{0,1,0,0}};
    vector<int> ans = minimalMoves(initial);
    for(int i : ans) cout << i << " "; cout << endl;
    return 0;
}
