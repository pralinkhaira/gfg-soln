class Solution {
  public:
  int ans=-1;
  void Solve(Node* root,int k){
      if(root==NULL)
      return;
      if(root->data<=k){
          ans=root->data;
          Solve(root->right,k);
      }
      else
      Solve(root->left,k);
  }
    int findMaxFork(Node* root, int k) {
        
        Solve(root,k);
        return ans;
    }
};

