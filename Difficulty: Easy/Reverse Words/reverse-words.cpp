//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    void reverseWord(string &str, int start, int end) {
        while (start < end) {
            swap(str[start], str[end]);
            start++;
            end--;
        }
    }

    string reverseWords(string str) {
        int n = str.length();

        // Reverse the entire string
        reverseWord(str, 0, n - 1);

        // Now reverse each word
        int start = 0;
        for (int end = 0; end <= n; end++) {
            // When we find a dot or reach the end of the string, reverse the word
            if (end == n || str[end] == '.') {
                reverseWord(str, start, end - 1);
                start = end + 1;
            }
        }

        return str;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends