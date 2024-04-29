//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    struct Node* reverseList(struct Node *head)
    {
     if(head == NULL || head->next == NULL){
         return head;
     }
     Node *prev = NULL;
     Node *curr = head;
     Node *forward = NULL;
     
     while(curr !=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
     }
     return prev;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        while(first!= nullptr && first->data ==0){
            first = first->next;
        }
        while(second!= nullptr && second->data ==0){
            second = second->next;
        }
        if(first == nullptr && second == nullptr) {
            Node* newNode =new Node(0);
            return newNode;
        }
        if(first == nullptr|| second == nullptr) {
            return first==nullptr?second:first;
        }
        
        Node* start1 = reverseList(first);
        Node* start2 = reverseList(second);
        Node* temp1 = start1;
        Node* temp2 = start2;

        Node* newList = NULL;
        Node* temp = NULL;
        int carry = 0;

        while (temp1 != NULL || temp2 != NULL || carry) {
            int sum = carry;
            if (temp1 != NULL) {
                sum += temp1->data;
                temp1 = temp1->next;
            }
            if (temp2 != NULL) {
                sum += temp2->data;
                temp2 = temp2->next;
            }

            carry = sum / 10;
            int digit = sum % 10;
            
            // create newNode and link it to resulting list
            Node* newNode = new Node(digit);
            if (newList == NULL) {
                newList = newNode;
                temp = newList;
            } else {
                temp->next = newNode;
                temp = temp->next;
            }
        }
        
        return reverseList(newList);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends