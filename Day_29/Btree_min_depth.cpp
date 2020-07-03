//LEETCODE minimum depth
//T(n) = O(n)

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

int minimum_depth(Node *root){
    if(root == NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    if(root->left==NULL){
        return minimum_depth(root->right)+1;
    }
    if(root->right==NULL){
        return minimum_depth(root->left)+1;
    }
    int l=minimum_depth(root->left);
    int r=minimum_depth(root->right);
    return min(l,r)+1;
}
int main(){

    Node *root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->right= new Node(15);
    root->right->left = new Node(21);

    cout<<minimum_depth(root);
        
    return 0;
}



