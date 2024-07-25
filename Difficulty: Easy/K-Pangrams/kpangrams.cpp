//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        vector<int> freq(26, 0);
        int unique_chars = 0;
        int total_chars = 0;
        
        // Count frequency of each character
        for (char c : str) {
            if (isalpha(c)) {
                int index = tolower(c) - 'a';
                if (freq[index] == 0) {
                    unique_chars++;
                }
                freq[index]++;
                total_chars++;
            }
        }
        
        // Check if we have enough characters to make a pangram
        if (total_chars < 26) {
            return false;
        }
        
        // Count missing characters
        int missing = 26 - unique_chars;
        
        // Check if we can make it a pangram
        return (missing <= k);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends