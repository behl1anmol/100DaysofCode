#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

void _verticalorder_traversal(Node *root,int hd,map<int , int>&m){

        if(root==NULL)
            return;

        if ( m.find(hd)== m.end() ) {
            m[hd]=(root->data);
        }

        _verticalorder_traversal(root->left,hd-1,m);

        _verticalorder_traversal(root->right,hd+1,m);

}

void vertical_order_traversal(Node *root){

    int hd=0;
    map <int, int> m;

    _verticalorder_traversal(root, hd, m);

    map <int, int> :: iterator it;

    for(it=m.begin(); it!=m.end(); it++){
        cout<<it->second<<" ";
    }
    
}
    void topView(Node * root) {
        vertical_order_traversal(root);

    }

}; 