/*
 T(n)=O(n)
S(n)=O(height)
*/


#include<bits/stdc++.h>

using namespace std;

class Node{

public:
    int data;
    Node *left;
    Node *right;

    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
bool search_node(Node* node,int x){

    if(node==NULL) return false;

    if(node->data==x) return true;

    return search_node(node->left,x) || search_node(node->right,x);
}
int main(){

    Node *root       = new Node(1); 
    root->left        = new Node(2); 
    root->right       = new Node(3); 
    root->left->left  = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left= new Node(6);
    root->right->right = new Node(7);

    vector<int> arr;
    int x;
    cin>>x;

    if(search_node(root,x)==true){

       cout<<"Node found";
    }
    else{
        cout<<"node not found";
    }
}