//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	//calculates the minimum health required to travel from (i,j) -> (n-1,m-1)
	int func(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp){
	    int n = mat.size();
	    int m = mat[0].size();
	    if(i>=n || j>=m) return 1e9;
	    if(dp[i][j]!=-1) return dp[i][j];
	    int min_health = min(func(i+1,j,mat,dp),func(i,j+1,mat,dp));
	    if(min_health==1e9) min_health = 1;
	    if(min_health-mat[i][j]<=0) min_health = 1;
	    else min_health = min_health-mat[i][j];
	    return dp[i][j] = min_health;
	}
	int minPoints(int n, int m, vector<vector<int>> mat) 
	{ 
	    vector<vector<int>> dp(n,vector<int>(m,-1));
	    return func(0,0,mat,dp);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends