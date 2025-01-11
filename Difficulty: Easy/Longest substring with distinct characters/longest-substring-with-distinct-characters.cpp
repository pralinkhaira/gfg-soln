//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        vector<int>freq(26,0);
        int ans = 0;
        // int cnt = 0;
        
        int i = 0,j = 0,n = s.length();
        while(j<n)
        {
            if(freq[s[j]-'a'] == 0)
            {
                freq[s[j]-'a']++;
                j++;
            }
            
            else
            {
                ans = max(ans,j-i);
                while(i<j && freq[s[j]-'a'] != 0)
                {
                    freq[s[i]-'a']--;
                    i++;
                }
                
            }
            
        }
        
        ans = max(ans,j-i);
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends