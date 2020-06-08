#include<bits/stdc++.h>
using namespace std;

//class declaration for BST
class Node{
public:
    Node *left;
    int data;
    Node *right;

    //constructor to initialize new
    Node(int data){
        left = NULL;
        right = NULL;
        this->data=data;
    }

    Node *insert(Node *root,int data);
};

int count_nodes(Node *root,int &n){
    if(root==NULL){
        return n;
    }
    n+=1;
    count_nodes(root->left,n);
    count_nodes(root->right,n);

    return n;
}

void inOrder(Node *root) {

        //if root initially empty return 
        if(root==NULL){
            return;
        }
        
        //traverse left subtree
        inOrder(root->left);

        //print data of node
        cout<<root->data<<" ";

        //traverse right subtree
        inOrder(root->right);
    }

int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right= new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    inOrder(root);
    int n=0;
    cout<<"Number of Nodes: "<<count_nodes(root,n); 
}