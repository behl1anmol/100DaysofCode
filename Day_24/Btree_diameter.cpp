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

int height(Node* root){

    if(root)
        return 1+max(height(root->left),height(root->right));

    return 0;    
}
/*
T(n) = O(n^2)
max diameter is
    1.max dia of left subtree
    2.max dia of right subtree
    3.longest path between leafs via root calculated via height
*/

int max_diameter(Node * root){

    if(root==NULL)
        return 0;

    return max((height(root->left)+height(root->right)+1),max(max_diameter(root->left),max_diameter(root->right)));

}

/*
T(n) = O(n)
max diameter is the maximum path leaf to leaf via root
*/
int max_diameter(Node* root,int &ans){
    if(root==NULL)
        return 0 ;

    int lh=max_diameter(root->left,ans);
    int rh=max_diameter(root->right,ans);
    

    ans=max(ans,(1+lh+rh));    
    return 1+max(lh,rh);    

}
int main(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right= new Node(5);

    int ans=0;
    max_diameter(root,ans);
    cout<<ans;
    return 0;
}