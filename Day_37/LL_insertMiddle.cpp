// GeeksforGeeks insert middle in LL T(N) = O(N)
#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    struct Node *next;
    
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// function to display the linked list
void display(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout<<endl;
}

Node* insertInMiddle(Node* head, int x);

int main()
{
    int T, n, x;
    cin>>T;
    while(T--)
    {
        cin>> n >> x;
        
        struct Node *head = new Node(x);
        struct Node *tail = head;
        
        for (int i=0; i<n-1; i++)
        {
            cin>>x;
            tail->next = new Node(x);
            tail = tail->next;
        }
        
        cin>> x;
        head = insertInMiddle(head, x);
        display(head);
    }
    return 0;
}
// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// function should insert node at the middle
// of the linked list
int countNodes(Node *head){
    int count=0;
    Node *temp = head;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
Node* insertInMiddle(Node* head, int x)
{
    if(head == NULL){
        return NULL;
    }
    Node *newNode = new Node(x);
    if(head->next == NULL){
        head->next = newNode;
        newNode->next=NULL;
        return head;
    }
    int pos = countNodes(head);
    pos = (pos%2==0)? pos/2 : (pos+1)/2 ; 
    pos--;
    Node *temp = head;
    
    while(pos--){
        if(temp->next == NULL){
            temp->next = newNode;
            newNode->next == NULL;
            return head;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
	
	return head;
}