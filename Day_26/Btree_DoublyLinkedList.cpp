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

class Node_ll{
    public:
        Node_ll *prev;
        int data;
        Node_ll *next;

        Node_ll(int data){
            prev=NULL;
            next==NULL;
            this->data=data;
        }


};

Node_ll * insert_end(Node *node, Node_ll *head){
    if(head==NULL){
        return new Node_ll(node->data);
    }
    Node_ll *temp = head; 
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node_ll *new_node = new Node_ll(node->data);
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next= NULL;
    return temp;
}

Node_ll* preorder(Node *root, Node_ll* head){
    if(root==NULL){
        return head;
    }
    Node_ll *temp = NULL;
    temp = insert_end(root,head);
    preorder(root->left, temp);
    preorder(root->right,temp);

    return temp;

}

void print_ll(Node_ll* head){
    if(head == NULL){
        cout<<"LL empty";
        return;
    }
    Node_ll* temp = head;

    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return;
}
    
int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right= new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node_ll *head = NULL;

    head = preorder(root, head);

    print_ll(head);


    return 0;



}