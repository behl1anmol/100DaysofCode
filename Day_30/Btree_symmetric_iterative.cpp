/*LEETCODE SYMMETRIC
1)left->right is symmetric to right->left
2)left->left issymmteric to right->right
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

};

bool isSymmetric(Node *root){
    queue<Node *>q;
    q.push(root);
    q.push(root);

    while(!q.empty()){
        Node *t1=q.front();
        q.pop();
        Node *t2=q.front();
        q.pop();
        if(t1 == NULL && t2 ==NULL)
            continue;
        if(t1 ==NULL || t2 == NULL) 
            return false;   
        if(t1->data != t2->data)
            return false;

        q.push(t1->left);
        q.push(t2->right);
        q.push(t1->right);
        q.push(t2->left);    
    }  
    return true;      
    
}

int main(){

    Node *root = NULL;

    if(isSymmetric(root)==true)
        cout<<"Yes";
    else
    {
        cout<<"No";
    }
    return 0;
}