//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:
    int find(int in[],int i,int j,int data){
        for(int k=i;k<=j;k++){
            if(in[k] == data){
                return k;
            }
        }
        return -1;
    }
    Node*solve(int in[],int post[],int i1,int j1,int j2,int n){
        if(i1 > j1){
            return nullptr;
        }
        int d = post[j2];
        Node * root = new Node(d);
        int ind = find(in,i1,j1,d);
        root->right = solve(in,post,ind+1,j1,j2-1,n);
        root->left = solve(in,post,i1,ind-1,j2 - (j1-ind+1),n);
        return root;
    }
    Node *buildTree(int in[], int post[], int n) {
        return solve(in,post,0,n-1,n-1,n);
    }
};



//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends