//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    // TC : O(N)
    // SC : O(1)
    int brute(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i ++) {
            string s = to_string(i);
            for (int j = 0; j < s.length(); j ++) { // max-len = 6 (for "100000" )
                if (s[j] == '4') {
                    ans += 1;
                    break;
                }
            }
        }
        return ans;
    }

    // TC : O(log(N))
    bool has_four(int n) {
        while(n > 0) {
            if (n % 10 == 4) {
                return 1;
            }
            n /= 10;
        }
        return 0;
    }

    // TC : O(Nlog(N))
    // SC : O(N)
    int approach_2(int n) {
        int ans = 0;
        int dp[n + 1] = {0};

        for (int i = 0; i <= n; i ++) {
            if (dp[i]) {
                ans += 1;
            } else {
                if (has_four(i)) {
                    dp[i] = 1;
                    ans += 1;
                }
            }
        }

        return ans;
    }
  public:
    int countNumberswith4(int n) {
        // return brute(n);

        return approach_2(n);

        // return approach_3(n); // Pending -> log(N) 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends