//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int del_row[4] = {-1, 1, 0, 0};
    int del_col[4] = {0, 0, -1, 1};
    bool valid(vector<vector<int>> &mat, vector<vector<int>> &vis, int row, int col, int n, int m)
    {
        if(row < 0 || row >= n || col < 0 || col >= m || mat[row][col] == 0 || vis[row][col] == 1)
            return 0;
        for (int k = 0; k < 4; k++)
        {
            int newRow = row + del_row[k];
            int newCol = col + del_col[k];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && mat[newRow][newCol] == 0)
                return 0;
        }
        return 1;
    }
    int findShortestPath(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            if (valid(mat, vis, i, 0, n, m))
            {
                vis[i][0] = 1;
                q.push({i, 0});
            }
        }
        int ans = 1;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                if (col == m - 1)
                    return ans;
                for (int i = 0; i < 4; i++)
                {
                    int newRow = row + del_row[i];
                    int newCol = col + del_col[i];
                    if (valid(mat, vis, newRow, newCol, n, m))
                    {
                        vis[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends