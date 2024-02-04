//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public: 
    string convertToString(Node* head) 
    { 
        string s = ""; 
        bool l = 0; 
        while(head) 
        { 
            if(head->data != 0) 
                l = 1; 
            if(l) 
                s += ('0' + head->data); 
            head = head->next; 
        } 
        return s; 
    } 
    Node* subLinkedList(Node* head1, Node* head2) { 
        string s1 = convertToString(head1), s2 = convertToString(head2); 
        if(s1.size() < s2.size()) 
            swap(s1, s2); 
        else if((s1.size() == s2.size()) && s1 <= s2) 
            swap(s1, s2); 
        int n = s1.size(), m = s2.size(); 
        int carry = 0; 
        int j = m - 1; 
        for(int i = n - 1; i >= 0; i--) 
        { 
            int val = (s1[i] - '0') - carry - ((j >= 0) ? (s2[j] - '0') : 0); 
            if(val < 0) 
            { 
                carry = 1; 
                s1[i] = ('0' + 10 + val); 
            } 
            else 
            { 
                carry = 0; 
                s1[i] = ('0' + val); 
            } 
            j--; 
        } 
        int i = 0; 
        while(i < n && s1[i] == '0') 
            i++; 
        LinkedList* ans = new LinkedList(); 
        while(i < n) 
            ans->insert((s1[i++] - '0')); 
        if(ans->head == nullptr) 
            ans->insert(0); 
        return ans->head; 
    } 
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends