class Solution {
  public:
    void solve(int i,int n, int k, vector<int> v, vector<vector<int>>& ans){
        if(n==0 && k==0){
            ans.push_back(v);
            return;
        }
        if(n<=0 || k<=0) return;
        
        for(int j = i;j<=9;j++){
            v.push_back(j);
            solve(j+1,n-j,k-1,v,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(1,n,k,v,ans);
        return ans;
    }
};