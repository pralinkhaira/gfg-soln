//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  public:
    vector<int> prime;
    vector<bool> isPrime;
    
    void f(){
        int MAX = 1e5 + 5;
        isPrime.assign(MAX, true);
        isPrime[0] = isPrime[1] = false;
        for(int i=2;i*i<=MAX;i++){
            if(isPrime[i]){
                for(int j=i*i;j<=MAX;j+=i){
                    isPrime[j] = false;
                }
            }
        }
        
        for(int j=2;j<=MAX;j++){
            if(isPrime[j]){
                prime.push_back(j);
            }
        }
    }
    
    Node *primeList(Node *head) {
        // code here
        f();
        Node *root = head;
        while(root){
            int Data = root->val;
            if(!isPrime[Data]){
                int ind = lower_bound(prime.begin(), prime.end(), Data) - prime.begin();
                if(ind > 0){
                    int data1 = prime[ind];
                    int data2 = prime[ind-1];
                    if(abs(data2 - Data) == abs(data1 - Data)){
                        root->val = data2;
                    }
                    else if(abs(data2 - Data) > abs(data1 - Data)){
                        root->val = data1;
                    }else{
                        root->val = data2;
                    }
                }else{
                    root->val = prime[ind];
                }
            }
            root = root->next;
        }
        return head;
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
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends