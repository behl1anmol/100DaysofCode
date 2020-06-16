#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    Node *left;
    int data;
    Node *right;

    
    Node(int data){
        left = NULL;
        right = NULL;
        this->data=data;
    }

    Node *insert(Node *root,int data);
};

int height(Node *root){

    if(root){
        return 1+ max(height(root->left),height(root->right));
    }
    return 0;
}
//T(n)=O(n^2)
bool balanced_btree(Node* root){
    if(root==NULL)
        return true;
    int lh=height(root->left);
    int rh=height(root->right);

    return (abs(lh-rh)<=1) && balanced_btree(root->left) && balanced_btree(root->right);    
}

/*
T(n)=O(n)
if the left or right subtree is unbalanced return -1.
idea is to calculate height and check for balanced 
btree in same function.
*/

int balanced_tree(Node *root){
    if(root==NULL)
        return 0;

    int lh = balanced_tree(root->left);
    if(lh==-1) return -1;

    int rh = balanced_tree(root->right);
    if(rh==-1) return -1;

    if(abs(lh-rh)>1) return -1;

    return max(lh,rh)+1; 
}
    

int main(){

    Node *root = new Node(8);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(13);
    root->left->right = new Node(14);
    root->right->right = new Node(16);
    root->right->right->right = new Node(17);

    int isbalanced=balanced_tree(root); 
    if(isbalanced !=-1){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}