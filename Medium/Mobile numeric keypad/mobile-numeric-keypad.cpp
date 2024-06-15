//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   long long solve(int n, std::map<int, std::vector<int>>& mp, int last, std::vector<std::vector<long long>>& dp) {
        if (n == 0) {
            return 1;
        }

        if (dp[n][last] != -1) {
            return dp[n][last];
        }

        long long cnt = 0;

        if (last == 11) {
            for (int i = 0; i <= 9; i++) {
                cnt += solve(n - 1, mp, i, dp);
            }
        } else {
            for (auto xx : mp[last]) {
                cnt += solve(n - 1, mp, xx, dp);
            }
        }

        return dp[n][last] = cnt;
    }
 
  
    long long getCount(int n) {
        // Your code goes here
        std::map<int, std::vector<int>> mp;

        mp[1] = {1, 2, 4};
        mp[2] = {1, 2, 5, 3};
        mp[3] = {2, 3, 6};
        mp[4] = {1, 4, 5, 7};
        mp[5] = {2, 4, 5, 6, 8};
        mp[6] = {3, 5, 6, 9};
        mp[7] = {4, 7, 8};
        mp[8] = {5, 7, 8, 9, 0};
        mp[0] = {0, 8};
        mp[9] = {6, 8, 9};

        std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(12, -1)); // Use long long for dp array

        return solve(n, mp, 11, dp);
        
        
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends