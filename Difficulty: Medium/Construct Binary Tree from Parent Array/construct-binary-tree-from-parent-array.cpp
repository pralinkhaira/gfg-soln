//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void sort_and_print(vector<int>& v) {
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    v.clear();
}

void printLevelOrder(struct Node* root) {
    vector<int> v;
    queue<Node*> q;

    q.push(root);

    Node* next_row = NULL;

    while (!q.empty()) {
        Node* n = q.front();
        q.pop();

        if (n == next_row) {
            sort_and_print(v);
            next_row = NULL;
        }

        v.push_back(n->data);

        if (n->left) {
            q.push(n->left);
            if (next_row == NULL)
                next_row = n->left;
        }

        if (n->right) {
            q.push(n->right);
            if (next_row == NULL)
                next_row = n->right;
        }
    }
    sort_and_print(v);
}

Node* createTree(int parent[], int n);

/* Driver program to test above function*/


// } Driver Code Ends
/* node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to construct binary tree from parent array.
    Node *createTree(vector<int> p) {
        unordered_map<int, Node*> mp;
        int r=-1;
        for(int i=0;i<p.size();i++)
        {
            if(p[i]==-1)
            {
                r= i;
                break;
            }
        }
        
        Node* root = new Node(r);
        mp[r]=root;
        
        for(int i=0;i<p.size();i++)
        {
            if(p[i]!=-1)
            {
                Node* b=NULL;
                if(mp.find(p[i])==mp.end())
                {
                    b= new Node(p[i]);
                    mp[p[i]]=b;
                    
                }
                b=mp[p[i]];
                    Node* node=NULL;
                    if(mp.find(i)==mp.end())
                    {
                       node= new Node(i); 
                       mp[i]=node;
                    }
                    node= mp[i];
                    if(b->left==NULL)
                    {
                        b->left= node;
                    }
                    else
                    {
                        b->right=node;
                    }
            }
        }
        
        return root;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }

        Solution ob;

        Node* res = ob.createTree(a);

        printLevelOrder(res);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends