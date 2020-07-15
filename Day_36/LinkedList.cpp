#include<bits/stdc++.h>
using namespace std;

class llNode{
public:
    int data;
    llNode *next;

    llNode(int data){
        next = NULL;
        this->data = data; 
    }

};

llNode *insertBeginning(llNode *head,int data){

    llNode *temp = new llNode(data);
    
    temp->next = head;
    head = temp;
    return head;
}

llNode *insertEnd(llNode *head,int data){
    if(head == NULL){
        head = new llNode(data);
        return head;
    }
    llNode *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new llNode(data);
    return head;
}

int main(){

    llNode *head = NULL;

    head = insertBeginning(head, 2);
    head = insertBeginning(head, 3);
    head = insertEnd(head, 4);
    head = insertEnd(head, 5);

    llNode *temp = head;

    while(temp != NULL){
        cout<<(temp->data)<<" ";
        temp = temp->next;
    }
    return 0;
}