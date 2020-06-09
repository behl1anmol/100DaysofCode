
//T(n)=O(n) && S(n)=O(1)
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

void k_node(Node *root,int k){

    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    
    k_node(root->left,k-1);
    k_node(root->right,k-1);
}
int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right= new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    int k;
    cin>>k;
    k_node(root,k); 
}