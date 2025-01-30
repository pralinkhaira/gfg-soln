//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> nQueen(int n) {
       
        vector<vector<int>> result;
        vector<int> board(n, 0);
        solve(0, n, board, result);
        return result;
    }

private:
    void solve(int col, int n, vector<int>& board, vector<vector<int>>& result) {
        if (col == n) {
            result.push_back(board);
            return;
        }
        
        for (int row = 0; row < n; row++) {
            if (isSafe(board, col, row)) {
                board[col] = row + 1;
                solve(col + 1, n, board, result);
            }
        }
    }
    
    bool isSafe(vector<int>& board, int col, int row) {
        for (int i = 0; i < col; i++) {
            int placedRow = board[i] - 1;
            if (placedRow == row || abs(placedRow - row) == abs(i - col)) {
                return false;
            }
        }
        return true;
  

        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends