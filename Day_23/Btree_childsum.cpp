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

//T(n) = O(n)
bool childsum(Node *root){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return true;
    }
    int sum=0;
    if(root->right!=NULL){
        sum=sum+root->right->data;
    }
    if(root->left!=NULL){
        sum=sum+root->left->data;
    }
    if(root->data==sum){
        return true;
    }
    else{
        return false;
    }
    childsum(root->left);
    childsum(root->right);

}

//T(n) = O(n)
bool childsum_iterative(Node *root){
    if(root==NULL){
        return false;
    }
    queue<Node *>q;

    q.push(root);
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();

        if(temp->left && temp->right){
            if(temp->data != temp->left->data + temp->right->data){
                return false;
            }    
                q.push(temp->left);
                q.push(temp->right);
        }
        else if(temp->left){
            if(temp->data != temp->left->data ){
                return false;
            }
            q.push(temp->left);
        }
        else if(temp->right){
            if(temp->data != temp->right->data ){
                return false;
            }
            q.push(temp->right);
        }
    } 
    return true;
}

int main(){

    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right= new Node(5);
    root->right->right = new Node(2);

    bool iscs=childsum_iterative(root);
    if(iscs==true){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

}