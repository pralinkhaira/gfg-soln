//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int solve(int i,int j, vector<vector<int>> &mat,int n,int m,int &maxi,vector<vector<int>> &dp){
        if(i>n-1 || j>m-1)
        return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        int right=solve(i,j+1,mat,n,m,maxi,dp);
        int bottom=solve(i+1,j,mat,n,m,maxi,dp);
        int diago=solve(i+1,j+1,mat,n,m,maxi,dp);
            
        if(mat[i][j]==1){
            maxi=max(maxi,1+min(right,min(bottom,diago)));
            dp[i][j]=1+min(right,min(bottom,diago));
            return dp[i][j];
        }
        else{
            dp[i][j]=0;
            return dp[i][j];
        }
        
    }
  
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        int maxi=0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        solve(0,0,mat,n,m,maxi,dp);
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends