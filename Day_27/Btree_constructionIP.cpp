#include<bits/stdc++.h>
using namespace std;

int pre_index=0;

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

Node *construct_btree(vector<int>in, vector<int>pre, int lb, int ub){

    if(lb>ub)
        return NULL;

    Node *root = new Node(pre[pre_index++]);

    int in_index;
    for(int i=0;i<in.size();i++){
        if(in[i] == root->data){
            in_index = i;
            break;
        }
    }

    root->left = construct_btree(in, pre, lb, in_index-1);
    root->right = construct_btree(in, pre, in_index+1, ub);

    return root;
}

void postorder(Node* root){

    if(root==NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

    return;
}

int main(){

    vector<int> in{20,10,40,30,50};
    vector<int> pre{10,20,30,40,50};

    Node * root = NULL;

    root = construct_btree(in, pre, 0, 4);

    postorder(root);

    return 0;


}