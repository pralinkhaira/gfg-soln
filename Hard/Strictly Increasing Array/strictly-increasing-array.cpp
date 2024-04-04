//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int min_operations(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int ans=n;
        for(int x=0;x<n;x++){
            for(int y=0;y<x;y++)
                if(nums[x]-nums[y] >= x-y)
                    dp[x]=max(dp[x],dp[y]+1);
            ans=min(ans,n-dp[x]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.min_operations(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends