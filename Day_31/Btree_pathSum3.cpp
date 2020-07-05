/*LEETCODE pathsum3
T(n) = O(n)
S(n) = o(1)
*/
#include<bits/stdc++.h>
using namespace std;

int c=0;
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

void pathSum(Node *root,int sum,int temp_sum){
    if(root==NULL)
        return;

    temp_sum = temp_sum - root->data;
    if(temp_sum < 0){
        temp_sum=sum;
    }
    if(temp_sum==0){
        temp_sum=sum;
        c++;
    }
    pathSum(root->left,sum,temp_sum);
    pathSum(root->right,sum,temp_sum);

        

}

int main(){

    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(-3);
    root->left->left = new Node(3);
    root->left->right= new Node(2);
    root->left->right->right = new Node(1);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(-2);
    root->right->right = new Node(11);

    int s,temp_sum;
    cout<<"Enter Sum:";
    cin>>s;

    temp_sum=s;

    pathSum(root,s,temp_sum);
    cout<<c;

    return 0;

}