//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    int mod = 1e9+7 ;
  
    int solve(string &s , int n , vector<int>&dp){
        if(n == 0 || n == 1)return 1 ;
        
        if(dp[n] != -1)return dp[n] ;
        
        int ans = 0 ;
        
        if(s[n-1] >= '1'){
            ans += solve(s , n-1 , dp)%mod ;
        }
        
        if(s[n-2] == '1' || s[n-2] == '2' && s[n-1] <= '6'){
            ans += solve(s , n-2 , dp)%mod ;
        }
        
        return dp[n] = ans%mod ;
    }
  
    int countWays(string &s) {
        // Code here
        int n = s.size() ;
        if(s[0] == '0')return 0 ;
        vector<int>dp(n+1 , -1) ;
        
        return solve(s , n , dp) ;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends