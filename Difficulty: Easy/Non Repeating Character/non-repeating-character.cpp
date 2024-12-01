//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    const int MAX_CHAR = 26;
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        // Your code here
        vector<int> freq(MAX_CHAR, 0);

        for (char c : s) 
        {
        freq[c - 'a']++;
        }
        
        for (int i = 0; i < s.length(); ++i)
       {
        if (freq[s[i] - 'a'] == 1)
        return s[i];
       }

    return '$';
    }
    
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;

    while (T--) {

        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonRepeatingChar(S);

        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends