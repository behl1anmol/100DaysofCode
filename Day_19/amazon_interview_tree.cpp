/*
Given sum a binary tree distroy all path having weight less than threshold weight in the tree.
T(n)=O(n)
S(n)=O(h)
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

    Node *insert(Node *root,int data);
};

Node * Node:: insert(Node *root,int data){
    
    if(root==NULL){
        return new Node(data);
    }    

    if(data<=root->data){

        Node *cur=new Node(data);
        cur=insert(root->left,data);
        root->left=cur;
    }
    else
    {
        Node *cur=new Node(data);
        cur=insert(root->right,data);
        root->right=cur;
    }
    
    return root;
        
}

bool is_leaf(Node *root){
    
    return (root->left==NULL && root->right==NULL);
}

void delete_Node(Node* &root, int threshold,int k){
    
    if(root==NULL){
        return;
    }

  
    k=k+ (root->data);
    delete_Node(root->left,threshold,k);
    delete_Node(root->right,threshold,k);

      if(is_leaf(root) && k<threshold){
        delete(root);
        root=NULL;
    }


    
}
  void inOrder(Node *root) {

        if(root==NULL){
            return;
        }
        inOrder(root->left);
        std::cout<<root->data<<" ";
        inOrder(root->right);
    }

int main(){

    int data,n;

    Node *root=NULL;
    cin>>n;

    while(n--){
        cout<<"Data: ";
        cin>>data;

        root= root->insert(root,data);
    }
    cout<<"\n Inorder traversal of new tree: ";

    int threshold,k=0;
    cin>>threshold;

    delete_Node(root,threshold,k);
    
    cout<<"\n Inorder traversal of new tree: ";
    inOrder(root);
    return 0;
}