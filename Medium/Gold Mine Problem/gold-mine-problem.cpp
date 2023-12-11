//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> dp;
    int func(int row, int col, vector<vector<int>> &matrix, int m, int n){
        if(row<0 || row>=m || col>=n){
            return 0;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int a = func(row-1, col+1, matrix, m, n);
        int b = func(row, col+1, matrix, m, n);
        int c = func(row+1, col+1, matrix, m, n);
        return dp[row][col] = max(a, max(b, c)) + matrix[row][col];
    }
    int maxGold(int m, int n, vector<vector<int>> matrix)
    {
        dp.resize(m, vector<int>(n, -1));
        int res = 0;
        for(int i=0; i<m; ++i){
            res = max(res, func(i, 0, matrix, m, n));
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends