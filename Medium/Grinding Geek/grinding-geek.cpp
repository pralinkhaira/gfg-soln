//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int dpf(int i, int j, vector<vector<int> > &dp, vector<int> &cost)
    {
        if(i==dp.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        dp[i][j] = dpf(i+1,j,dp,cost);
        if(j >= cost[i])
        {
            dp[i][j] = max(dp[i][j], 1 + dpf(i+1, j - cost[i] + ((9*cost[i])/10), dp, cost));
        }
        return dp[i][j];
    }
    public:
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<vector<int> > dp(n,vector<int>(total+1,-1));
        return dpf(0,total,dp,cost);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends