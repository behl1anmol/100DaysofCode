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

int max_node(Node *root){
    if(root==NULL){
        return 0;
    }

    return max(root->data,max(max_node(root->left),max_node(root->right)));
    
}
int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right= new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(4);

    cout<<"Maximum: "<<max_node(root); 
}