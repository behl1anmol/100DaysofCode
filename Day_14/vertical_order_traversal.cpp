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

void _verticalorder_traversal(Node *root,int hd,map<int , vector<int>>&m){

        if(root==NULL)
            return;

        m[hd].push_back(root->data);

        _verticalorder_traversal(root->left,hd-1,m);

        _verticalorder_traversal(root->right,hd+1,m);

}

void vertical_order_traversal(Node *root){

    int hd=0;
    map <int, vector<int>> m;

    _verticalorder_traversal(root, hd, m);

    map <int, vector<int>> :: iterator it;

    for(it=m.begin(); it!=m.end(); it++){


        for(int i=0;i<it->second.size(); i++){
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
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

    vertical_order_traversal(root);
    return 0;
}