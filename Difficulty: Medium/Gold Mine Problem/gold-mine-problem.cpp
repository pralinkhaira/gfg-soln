class Solution {
private:
    bool isSafe(int i, int j, int n, int m)
    {
        return (i>=0 && j>=0 && i<n && j<m);
    }

    int dfs(int i, int j, int n, int m, vector<vector<int>> &mat, 
    vector<vector<int>> &dp)
    {
        if(!isSafe(i,j,n,m))    return 0;
        if(dp[i][j]!=-1)    return dp[i][j];
        
        int one=dfs(i-1,j+1,n,m,mat,dp);
        int two=dfs(i,j+1,n,m,mat,dp);
        int three=dfs(i+1,j+1,n,m,mat,dp);
        
        dp[i][j]=max({one,two,three})+mat[i][j];
        return dp[i][j];
    }
    
public:
    int maxGold(vector<vector<int>> &mat)
    {
        int n=mat.size(), m=mat[0].size(), mx=INT_MIN;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        for(int i=0; i<n ; i++) {
            if(dp[i][0]==-1)    dfs(i,0,n,m,mat,dp);
            mx=max(mx,dp[i][0]);
        }
        
        return mx;
    }
};