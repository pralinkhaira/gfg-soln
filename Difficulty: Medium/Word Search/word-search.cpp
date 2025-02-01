//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool dfs(int row, int col, int index, vector<vector<char>> &board, string word, vector<vector<int>> &vis){
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, -1, 0, +1};
        
        if(index == word.size()){
            return true;
        }
        
        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == word[index]){
                if(dfs(nrow, ncol, index+1, board, word, vis) == true){
                    return true;
                }
        }
    }
        vis[row][col] = 0;
         return false;
    }
   
    bool isWordExist(vector<vector<char>>& board, string word) {
         int n = board.size();
         int m = board[0].size();
         vector<vector<int>> vis(n, vector<int>(m, 0));
         for(int i=0; i<n; i++){
             for(int j=0; j<m; j++){
                 if(board[i][j] == word[0]){
                     if(dfs(i, j, 1, board, word, vis) == true){
                         return true;
                     }
                 }
             }
         }
         return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends