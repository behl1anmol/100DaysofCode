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

    bool isUnivalTree(Node* root) {
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return true;   

    if(root->right == NULL){
        return( (root->data == root->left->data) && isUnivalTree(root->left));
    }
    if(root->left == NULL){
        return( (root->data == root->right->data) && isUnivalTree(root->right));
    }
    
    return (root->data==root->left->data && root->data==root->right->data && isUnivalTree(root->left) && isUnivalTree(root->right));
        
    }
int main(){

    Node *root = new Node(2);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->right= new Node(2);
    root->left->left = new Node(2);

    if(isUnivalTree(root) == true)
        cout<<"Yes";
    else
    {
            cout<<"No";
    }
        
    return 0;
}



