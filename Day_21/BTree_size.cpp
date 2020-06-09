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

int count_nodes(Node *root){
    if(root==NULL){
        return 0;
    }
    return count_nodes(root->left)+1+count_nodes(root->right);
}


    

int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right= new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);


    cout<<"Number of Nodes: "<<count_nodes(root); 
}