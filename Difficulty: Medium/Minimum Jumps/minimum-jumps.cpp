//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int helper(int i, vector<int>& arr, int n, vector<int>& dp){
        // base case
        if(i == n-1){
            return 0;
        }
        
        if(dp[i] != -1) return dp[i];
        
        int ans = INT_MAX;
        for(int j = i+1; j <= (i+arr[i]) && j < n; j++){
            int val = helper(j, arr, n, dp);
            
            if(val != INT_MAX){
                ans = min(ans, val+1);
            }
        }
        return dp[i] = ans;
    }
    
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n, -1);
        int ans = helper(0, arr, n, dp);
        
        if(ans == INT_MAX) return -1;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends