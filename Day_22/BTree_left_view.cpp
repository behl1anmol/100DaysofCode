#include<bits/stdc++.h>
using namespace std;

int maxlevel=0;
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

void print_leftview(Node *root,int level){

    if(root==NULL)
        return;

    if(maxlevel<level){
        cout<<root->data<<" ";
        maxlevel=level;
    }
    print_leftview(root->left, level+1);
    print_leftview(root->right,level+1);            
} 

int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right= new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    print_leftview(root,1);

}