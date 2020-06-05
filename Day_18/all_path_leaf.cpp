/*
 T(n)=O(n)
S(n)=O(height)
*/
#include<bits/stdc++.h>

using namespace std;

class Node{

public:
    int data;
    Node *left;
    Node *right;

    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

void print(vector<int>&arr){


        for(int i=0;i<arr.size()-1;i++){
            cout<<arr[i]<<"---";
        }
        cout<<arr[arr.size()-1]<<endl;
    

    return;

}

void path_leaf(Node* node,vector<int> & arr){

    if(node==NULL)
        return;
    arr.push_back(node->data);

    if ((node->left==NULL && node->right==NULL)){
        print(arr);
    }
    else{
        path_leaf(node->left,arr);
        path_leaf(node->right,arr);
    }
    arr.pop_back();
    
}

int main(){

    Node *root       = new Node(10); 
    root->left        = new Node(8); 
    root->right       = new Node(2); 
    root->left->left  = new Node(3); 
    root->left->right = new Node(5); 
    root->right->left= new Node(2);

    vector<int> arr;

    path_leaf(root,arr);

    return 0;

}