//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countWays(int n) {
        // your code here
        if(n<=2) return n;
        vector<int> dp(n+1, 0);
        dp[n] = 1; dp[n-1] = 1;
        
        for(int i=n-2; i>=0; i--){
            dp[i] = dp[i+1] + dp[i+2];
        }
        
        return dp[0];
    }
};

//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends