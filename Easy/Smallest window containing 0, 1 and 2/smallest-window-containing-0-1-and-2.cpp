//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int smallestSubstring(string s) {
        int i=0,j=0,n= s.size(), ans = INT_MAX;
        vector<int> freq(3,0);
        while(j<n){
            freq[s[j]-'0']++;
            while(freq[0] && freq[1] && freq[2] && i<= j){
                ans = min(ans,j-i+1);
                freq[s[i]-'0']--;
                i++;
            }
            j++;
        }
        return ans == INT_MAX ? -1: ans ;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends