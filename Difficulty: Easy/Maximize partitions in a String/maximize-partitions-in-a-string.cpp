//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        map<char, int> mp;
        for(int i=0;i<s.size(); i++){
            mp[s[i]] = i;
        }
        
        int end = 0;
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            end = max(end, mp[s[i]]);
            if(end == i)
                ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends