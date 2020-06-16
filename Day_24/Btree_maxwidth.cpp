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
void max_width(Node *root){
    if(root==NULL){
        return;
    }
    queue<Node *>q;
    q.push(root);
    cout<<1<<endl;

    while(!q.empty()){
        int width=0;
        int size=q.size();

        while(size--){
            Node* temp=q.front();
            q.pop();

            if(temp->left !=NULL){
                width++;
                q.push(temp->left);
            }

            if(temp->right !=NULL){
                width++;
                q.push(temp->right);
            }
        }
        if(width!=0)
            cout<<width<<endl;
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

    max_width(root);
    return 0;
}