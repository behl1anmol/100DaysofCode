/*LEETCODE SYMMETRIC
1)left->right is symmetric to right->left
2)left->left issymmteric to right->right
*/
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

};

bool isSymmetric(Node *root, Node *copy_root){
    if(root==NULL && copy_root==NULL)
        return true;
    if(root==NULL || copy_root==NULL)
        return false;

    return (root->data==copy_root->data) && isSymmetric(root->left,copy_root->right) && isSymmetric(root->right,copy_root->left);        
    
    
}

int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right= new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    if(isSymmetric(root,root)==true)
        cout<<"Yes";
    else
    {
        cout<<"No";
    }
    return 0;
}