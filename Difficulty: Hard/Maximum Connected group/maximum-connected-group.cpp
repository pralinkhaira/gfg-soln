//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet {

public:
    vector<int> rank, parent, size;

    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        u = findUPar(u);
        v = findUPar(v);
        if (u == v)
            return;

        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        }
        else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

class Solution {
public:
    bool isValid(int r, int c, int n)
    {
        return r >= 0 && r < n && c >= 0 && c < n;
    }

    int MaxConnection(vector<vector<int> >& grid)
    {
        // code here
        int n = grid.size();
        DisjointSet ds(n * n);
        vector<int> dr = { -1, 0, 1, 0 };
        vector<int> dc = { 0, -1, 0, 1 };

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0)
                    continue;

                for (int ind = 0; ind < 4; ind++) {
                    int r = row + dr[ind];
                    int c = col + dc[ind];

                    if (isValid(r, c, n)
                        && grid[r][c] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = r * n + c;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1)
                    continue;

                set<int> components;
                for (int ind = 0; ind < 4; ind++) {
                    int r = row + dr[ind];
                    int c = col + dc[ind];
                    if (isValid(r, c, n)) {
                        if (grid[r][c] == 1) {
                            components.insert(
                                ds.findUPar(r * n + c));
                        }
                    }
                }
                int sizeTotal = 0;
                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal + 1);
            }
        }

        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            mx = max(mx, ds.size[ds.findUPar(cellNo)]);
        }

        return mx;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends