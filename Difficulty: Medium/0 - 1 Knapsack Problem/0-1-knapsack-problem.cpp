//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(int i, int w, vector<vector<int>>& dp, vector<int>& wt, vector<int>& val){
        if(i< 0) return 0;
        if(dp[i][w] != - 1) dp[i][w];
        int take = INT_MIN;
        if(wt[i] <= w) take = val[i] + f(i-1, w-wt[i], dp, wt, val);
        int nottake = f(i-1, w, dp, wt, val);
        return dp[i][w] = max(take, nottake);
    }
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return f(n-1, W, dp, wt, val);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends