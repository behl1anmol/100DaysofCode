/*
Given sum a binary tree distroy all path having weight less than threshold weight in the tree.
T(n)=O(n)
S(n)=O(h)
*/
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

    // if left and right child of the node is NULL return true else false
    return (root->left==NULL && root->right==NULL);
}

void delete_Node(Node* &root, int threshold,int sum){
    
    //if tree initially empty then return NULL
    if(root==NULL){
        return;
    }

    //add the data of node to the sum so far
    sum=sum+ (root->data);

    //traverse towards the left subtree
    delete_Node(root->left,threshold,sum);

    //traverse towards the right subtree
    delete_Node(root->right,threshold,sum);

    /*if the node is leaf node and complete path 
      is less than threshold then delete the node
      from the tree*/
      if(is_leaf(root) && sum<threshold){
        delete(root);
        root=NULL;
    }


    
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

    int data,n;

    Node *root=NULL;
    cin>>n;

    while(n--){
        cout<<"Data: ";
        cin>>data;

        root= root->insert(root,data);
    }
 
    int threshold,k=0;
    cin>>threshold;

   cout<<"\n Inorder traversal of intital tree: ";
   inOrder(root);
    delete_Node(root,threshold,k);
    
    cout<<"\n Inorder traversal of new tree: ";
    inOrder(root);
    return 0;
}