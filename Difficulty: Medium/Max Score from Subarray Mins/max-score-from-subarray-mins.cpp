class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n=arr.size();
        int ans=-1;
        for(int i=1;i<n;i++){
            int x=arr[i-1]+arr[i];
            ans=max(x,ans);
        }
        return ans;
    }
};