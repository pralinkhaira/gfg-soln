//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    bool check(vector<vector<int>>& a, int mid) {
        int n = a.size();
        int m = a[0].size();
        bool vis[n][m];
        memset(vis, false, sizeof(vis));
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = true;
        vector<int> xdir = {1, 0, -1, 0};
        vector<int> ydir = {0, -1, 0, 1};
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            if (temp.first == n - 1 && temp.second == m - 1)
                return true;
            for (int k = 0; k < 4; ++k) {
                int x = temp.first + xdir[k];
                int y = temp.second + ydir[k];
                if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y] ||
                    abs(a[x][y] - a[temp.first][temp.second]) > mid)
                    continue;
                q.push({x, y});
                vis[x][y] = true;
            }
        }
        return false; // If we reach here, it means we couldn't reach the destination
    }
    int MinimumEffort(int rows, int columns, vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        int l = 0, h = 1e6;
        while (l < h) {
            int mid = l + (h - l) / 2;
            if (check(heights, mid))
                h = mid; // If feasible, update the high value
            else
                l = mid + 1; // If not feasible, update the low value
        }
        return l; // Returning the minimum effort.
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends