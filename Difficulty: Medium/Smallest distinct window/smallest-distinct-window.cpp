//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        int n = str.length();
        if (n == 0) return 0;

        // Step 1: Find total unique characters in the string
        unordered_set<char> unique_chars(str.begin(), str.end());
        int required = unique_chars.size();

        // Step 2: Use sliding window
        unordered_map<char, int> window_counts;
        int formed = 0;
        int min_len = n + 1;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            char c = str[right];
            window_counts[c]++;
            
            if (window_counts[c] == 1) { // First time this character is included
                formed++;
            }

            // Try to shrink the window
            while (formed == required) {
                min_len = min(min_len, right - left + 1);

                char left_char = str[left];
                window_counts[left_char]--;
                if (window_counts[left_char] == 0) {
                    formed--;
                }
                left++;
            }
        }

        return min_len;
    }
};

//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends