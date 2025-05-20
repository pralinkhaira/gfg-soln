class Solution {
  public:

    // Helper function to calculate the maximum depth (height) of the tree
    int maxDepth(Node* root) {
        if(root == NULL){
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    // Helper function to simulate the burning process and calculate time
    int travel(Node* root, int &ans, int &target) {
        // If current node is null, target not found here
        if(root == NULL){
            return 0;
        }

        // If current node is the target
        if(root->data == target){
            // Calculate max depth of left and right subtrees
            int lft = maxDepth(root->left);
            int rgt = maxDepth(root->right);
            // Max of both sides will be the farthest burn time from the target
            ans = max(lft, rgt);
            return 1;  // return distance from target node
        }

        // Search in left subtree
        int lh = travel(root->left, ans, target);
        if(lh){
            // Update answer with right subtree depth + distance from target
            ans = max(ans, lh + maxDepth(root->right));
            return 1 + lh;  // Increment distance as we go up
        }

        // Search in right subtree
        int rh = travel(root->right, ans, target);
        if(rh){
            // Update answer with left subtree depth + distance from target
            ans = max(ans, rh + maxDepth(root->left));
            return 1 + rh;  // Increment distance
        }

        // Target not found in this subtree
        return 0;
    }

    // Main function to be called
    int minTime(Node* root, int target) {
        int ans = 0;
        travel(root, ans, target);
        return ans;  // Time taken to burn the entire tree
    }
};
