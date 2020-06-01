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

Node * insert(Node *root,int data){
    
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

void _level_order_traversal(Node *root,queue<int> &q){

    if(root==NULL)
        return;


    if(root->left!=NULL)
        q.push(root->left->data);
    if(root->right!=NULL)
        q.push(root->right->data);

    _level_order_traversal(root->left,q);
    _level_order_traversal(root->right,q);

    return;

}
void level_order_traversal(Node *root){
    if(root==NULL)
        return;

    queue<int> q;

    q.push(root->data);
    _level_order_traversal(root,q);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return;

}

void iterative_levelOrder(Node * root){
        
        if(root==NULL)
            return;
        
        queue<Node*> q;

        q.push(root); 

        while(!q.empty()){
            
            Node *temp=q.front();
            cout<<temp->data<<" ";
            q.pop();

            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
            
        }
  	
  
	}
int main(){

    int data,n;

    Node *root=NULL;

    cin>>n;

    while(n--){
        cout<<"Data: ";
        cin>>data;

        root= insert(root,data);
    }

    level_order_traversal(root);
    return 0;
}