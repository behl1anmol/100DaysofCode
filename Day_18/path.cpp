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

bool search_node(Node* node,int x,vector<int> & arr){

    if(node==NULL){
        return false;
    }
    arr.push_back(node->data);

    if(node->data==x) return true;

    if (search_node(node->left,x,arr) || search_node(node->right,x,arr))
            return true;

    arr.pop_back();
    return false;
    
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

    if(search_node(root,x,arr)==true){

        for(int i=0;i<arr.size()-1;i++){
            cout<<arr[i]<<"---";
        }
        cout<<arr[arr.size()-1];
    }
    else{
        cout<<"node not found";
    }
}