//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int editDistance(string str1, string str2) {
        int n = str1.size(), m =str2.size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return solve(0,0,n,m,str1,str2,dp);
    }
    int solve(int i,int j,int n,int m,string str1,string str2,vector<vector<int>> &dp){
        
        if(i==n){
            //insert extra char from str2
            return m-j;
        }
        if(j==m){
            //delete extra char from str1
            return n-i;
        }
        
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        
        if(str1[i]==str2[j])    return dp[i][j] = solve(i+1,j+1,n,m,str1,str2,dp);
        
        //insert
        int insertion = solve(i,j+1,n,m,str1,str2,dp);
        
        //delete
        int deletion = solve(i+1,j,n,m,str1,str2,dp);
        
        //replace
        int replace = solve(i+1,j+1,n,m,str1,str2,dp);
        
        return dp[i][j] = 1+min(insertion, min(deletion,replace));
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends