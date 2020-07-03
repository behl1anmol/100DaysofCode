//LEETCODE same tree
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

bool same_tree(Node *root,Node *root_new){
    if(root==NULL && root_new==NULL)
        return true;
    if(root==NULL && root_new!=NULL)
        return false;
    if(root!=NULL && root_new==NULL)
        return false;    
    return (root->data==root_new->data) && same_tree(root->left,root_new->left) && same_tree(root->right,root_new->right);
}
int main(){

    Node *root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->right= new Node(15);
    root->right->left = new Node(21);

    Node *root_new = new Node(3);
    root_new->left = new Node(9);
    root_new->right = new Node(20);
    root_new->right->right= new Node(15);
    //root_new->right->left = new Node(21);

    if(same_tree(root,root_new)==true)
        cout<<"YES";
    else
    {
        cout<<"No";
    }
        
        
    return 0;
}



