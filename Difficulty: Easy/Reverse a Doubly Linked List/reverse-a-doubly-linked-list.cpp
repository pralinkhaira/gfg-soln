/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
*/

class Solution {
  public:
    Node *reverse(Node *head) {
        if (!head || !head->next) return head; // empty or single node

        Node* curr = head;
        Node* temp = NULL;

        // Traverse the DLL
        while (curr != NULL) {
            // Swap prev and next
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            // Move to the "next" node (actually prev after swap)
            curr = curr->prev;
        }

        // After the loop, temp points to the node before NULL (new head)
        if (temp != NULL) {
            head = temp->prev;
        }

        return head;
    }
};