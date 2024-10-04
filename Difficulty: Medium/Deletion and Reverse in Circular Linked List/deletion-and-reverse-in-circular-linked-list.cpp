//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}


// } Driver Code Ends
class Solution {
  public:
     // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        // code here
       
        if(head->next == head) return head;
        Node *prev = NULL;
        Node *newhead = head;
        while(head->next!=newhead)
        {
            Node *temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
         head->next = prev;
            prev = head;
        newhead->next = prev;
        return prev;
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        // code here
        Node *newhead = head;
        while(head->next != newhead)
        {
            head = head->next;
        }
        Node *prev = head;
        head = newhead;
        int i = 0;
         while(head->next!=newhead)
        {
            if(head->data == key)
            {
                prev->next = head->next;
                if(i == 0) newhead = head->next;
                break;
            }
            prev = head;
            head = head->next;
            i++;
        }
        if(head->data == key)
            {
                prev->next = head->next;
                
            }
        return newhead;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}

// } Driver Code Ends