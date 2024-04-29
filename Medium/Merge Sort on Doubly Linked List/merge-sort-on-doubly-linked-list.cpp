//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends

/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

Node* mersrt(Node* curr1,Node* curr2){
    if(!curr1){
        return curr2;
    }
    if(!curr2){
        return curr1;
    }
    Node*result=NULL;
    if(curr1->data<curr2->data){
        result=curr1;
        result->next=mersrt(curr1->next,curr2);
        if(result->next){
            result->next->prev=result;
        }
    }else{
        result=curr2;
        result->next=mersrt(curr1,curr2->next);
        if(result->next){
            result->next->prev=result;
        }
    } return result;
}
Node* mergin(Node*head){
    if(!head || !head->next){
        return head;
    }
    Node*slow=head;
    Node*fast=head;
    while(fast->next&&fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node*curr2=slow->next;
    slow->next=NULL;
    curr2->prev=NULL;
    return curr2;
}
class Solution {
  public:
    // Function to sort the given doubly linked list using Merge Sort.
    struct Node *sortDoubly(struct Node *head) {
        // Your code here
        if(!head || !head->next){
            return head;
        }
        Node* curr2=mergin(head);
        head=sortDoubly(head);
        curr2=sortDoubly(curr2);
        return mersrt(head,curr2);
    }
};


//{ Driver Code Starts.

void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Driver program
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}

// } Driver Code Ends