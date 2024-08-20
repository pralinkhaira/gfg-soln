//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
 class Solution {
  public:
    Node* makeNodetoParentMappingAndFind(Node* root , unordered_map<Node*,Node*>&parentMap, int target){
        queue<Node*>q;
        Node*targetNode = 0;
        q.push(root);
        parentMap[root] = 0;
        while(!q.empty()){
            Node* front = q.front(); q.pop();
            if(front -> data == target){
                targetNode = front;
            }
            if(front -> left){
                q.push(front -> left);
                parentMap[front -> left] = front;
            }
            if(front -> right){
                q.push(front -> right);
                parentMap[front -> right] = front;
            }
        }
        return targetNode;
    }
    
    int burntheTree(Node* targetNode,unordered_map<Node*,Node*>&parentMap){
        unordered_map<Node* , bool>isBurnt;
        queue<Node*>q;
        int T = 0;
        q.push(targetNode);
        isBurnt[targetNode] = 1;
        while(!q.empty()){
            int size = q.size();
            bool isFireSpreaded = 0;
            for(int i=0;i<size;i++){
                Node* front = q.front();
                q.pop();
                if(front -> left && !isBurnt[front -> left]){
                    q.push(front -> left);
                    isBurnt[front -> left] = 1;
                    isFireSpreaded = 1;
                }
                
                 if(front -> right && !isBurnt[front -> right]){
                    q.push(front -> right);
                    isBurnt[front -> right] = 1;
                    isFireSpreaded = 1;
                }
                
                if(parentMap[front] && !isBurnt[parentMap[front]]){
                    q.push(parentMap[front]);
                    isBurnt[parentMap[front]] = 1;
                    isFireSpreaded = 1;
                }
            }
            if(isFireSpreaded) T++;
        }
        return T;
    }
    
    
    int minTime(Node* root, int target) 
    {
    
        unordered_map<Node*,Node*>parentMap;
        Node*targetNode = makeNodetoParentMappingAndFind(root,parentMap,target);
        return burntheTree(targetNode,parentMap);
        
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends