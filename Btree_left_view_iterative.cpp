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

};

void levelorder(Node *root){

    if(root==NULL)
        return;

    queue<Node *>q;
    q.push(root);

    while(q.empty() == false){
        int size=q.size();
        int temp_level=0;

        while(size>0){
            Node *temp=q.front();

            if(temp_level==0){
                cout<<temp->data<<" ";
                temp_level++;
            }
            q.pop();
            if(temp->left!=NULL) 
                q.push(temp->left);
            if(temp->right!=NULL)    
                q.push(temp->right);
            size--;    

        }
        cout<<endl;
    }

}

int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right= new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    levelorder(root);

}