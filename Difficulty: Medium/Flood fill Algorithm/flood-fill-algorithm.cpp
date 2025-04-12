//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    private:
       void dfs(int row, int col, int ini, vector<vector<int>>& image,
         vector<vector<int>>& ans, int newColor, vector<int>& dr, vector<int>& dc)
{
    ans[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();

    for (int i = 0; i < 4; i++) {
        int nrow = row + dr[i];
        int ncol = col + dc[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            image[nrow][ncol] == ini && ans[nrow][ncol] != newColor) {
            dfs(nrow, ncol, ini, image, ans, newColor, dr, dc);
        }
    }
}
  public:
   vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int ini = image[sr][sc];
    vector<vector<int>> ans = image;

    if (ini == newColor) return ans; 

    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    dfs(sr, sc, ini, image, ans, newColor, dr, dc);
    return ans;
}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends