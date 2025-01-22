//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
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

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
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

class Solution {
  public:
    // Function to reverse the linked list
    Node* reverse(Node* head) {
        // Initialize the previous node as NULL
        Node* prev = NULL;
        // Start with the current node as the head
        Node* current = head;
        // Variable to store the next node temporarily
        Node* next;

        // Traverse the list until the current node becomes NULL
        while (current != NULL) {
            // Store the next node
            next = current->next;
            // Reverse the pointer of the current node
            current->next = prev;
            // Move the previous node to the current node
            prev = current;
            // Move to the next node in the list
            current = next;
        }

        // Return the new head of the reversed list (the last non-NULL node)
        return prev;
    }

    // Function to add two numbers represented as linked lists
    Node* addTwoLists(Node* num1, Node* num2) {
        // Reverse both linked lists to add the numbers from the least significant digit
        num1 = reverse(num1);
        num2 = reverse(num2);

        // Initialize the resulting sum list as NULL
        Node* sum = NULL;
        // Variable to store the carry from the previous digit addition
        int carry = 0;

        // Loop until both lists are exhausted or there's a remaining carry
        while (num1 != NULL || num2 != NULL || carry != 0) {
            // Start with the carry value
            int newVal = carry;

            // Add the value of num1's current node, if it exists
            if (num1) {
                newVal += num1->data;
                // Move to the next node in num1
                num1 = num1->next;
            }
            // Add the value of num2's current node, if it exists
            if (num2) {
                newVal += num2->data;
                // Move to the next node in num2
                num2 = num2->next;
            }

            // Update the carry (the quotient of newVal divided by 10)
            carry = newVal / 10;
            // Get the current digit to be placed in the sum (the remainder of newVal
            // divided by 10)
            newVal = newVal % 10;

            // Create a new node for the current digit and insert it at the beginning of
            // the sum list
            Node* newNode = new Node(newVal);
            newNode->next = sum;
            sum = newNode;
        }

        // Remove any leading zeros from the result (if applicable)
        while (sum != NULL && sum->data == 0) {
            // If the current node is 0, delete it and move to the next node
            Node* temp = sum;
            sum = sum->next;
            delete temp;
        }

        // If the sum list is empty after removing leading zeros, return a node with
        // value 0
        if (sum == NULL) {
            return new Node(0);
        }
        // Return the head of the sum list
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends