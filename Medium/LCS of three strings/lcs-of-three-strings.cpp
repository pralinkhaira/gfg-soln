//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    // int count = 0;
    int solve(int i1, int i2, int i3, string a, string b, string c, int n1, int n2, int n3, vector<vector<vector<int>>> &dp)
    {
        // cout << i1 << ":" << i2 << ":" << i3 << " ";
        // count++;
        if(i1 == n1 or i2 == n2 or i3 == n3)
            return 0;
        if(dp[i1][i2][i3] != -1)
            return dp[i1][i2][i3];
        if(a[i1] == b[i2] and a[i1] == c[i3])
            return 1 + solve(i1 + 1, i2 + 1, i3 + 1, a, b, c, n1, n2, n3, dp);
        int d = solve(i1 + 1, i2, i3, a, b, c, n1, n2, n3, dp);
        int e = solve(i1, i2 + 1, i3, a, b, c, n1, n2, n3, dp);
        int f = solve(i1, i2, i3 + 1, a, b, c, n1, n2, n3, dp);
        return dp[i1][i2][i3] = max(d, max(e, f));
    }
    public:
    int LCSof3(string A, string B, string C, int n1, int n2, int n3)
    {
        // your code here
        vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, -1)));
        int ans = solve(0, 0, 0, A, B, C, n1, n2, n3, dp);
        // cout << count << endl;
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends