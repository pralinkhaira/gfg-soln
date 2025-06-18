#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Helper function to check if a substring is a palindrome
    bool isPalindrome(const string &s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }

    // DFS function to find palindrome partitions
    void dfs(int i, string &s, vector<string> &path, vector<vector<string>> &res) {
        if (i == s.length()) {
            res.push_back(path); // Reached the end, add current path
            return;
        }
        for (int j = i; j < s.length(); ++j) {
            if (isPalindrome(s, i, j)) {
                path.push_back(s.substr(i, j - i + 1)); // Add palindromic substring
                dfs(j + 1, s, path, res);               // Recurse for remaining string
                path.pop_back();                        // Backtrack
            }
        }
    }

    // Main function
    vector<vector<string>> palinParts(string &s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(0, s, path, res);
        return res;
    }
};
