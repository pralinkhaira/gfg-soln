//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string longestSubstring(string s, int n) {
       // code here
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    int mx_length = 0, last = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (s[i - 1] == s[j - 1] && dp[i - 1][j - 1] < (j - i)) {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                if (dp[i][j] > mx_length) {
                    mx_length = dp[i][j];
                    last = i - 1;
                }
            }
        }
    }

    if (mx_length == 0) {
        return "-1";
    } else {
        return s.substr(last - mx_length + 1, mx_length);
    }
       
   }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends