//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
  int n , m;
  vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    void DFS(vector<vector<int>>& mat,vector<vector<int>>& vis, int i,int j){
        vis[i][j]=1;
        for (auto dir : dirs) {
            int ni = i + dir[0], nj = j + dir[1];
            if (ni >= 0 && nj >= 0 && ni < n && nj < m &&
                !vis[ni][nj] && mat[ni][nj] >= mat[i][j]) {
                DFS(mat, vis, ni, nj);
            }
        }
    }
    int countCoordinates(vector<vector<int> > &mat) {
       // Start from all Pacific border cells and do DFS/BFS from there, only going to cells with equal or higher height.
       // Repeat the same for Atlantic border cells.
       // The intersection of the two visited regions gives you the cells that can reach both oceans.
       n = mat.size();
       // if(n == 0) return -1;
       m = mat[0].size();
       vector<vector<int>> pacific(n,vector<int>(m,0));
       vector<vector<int>> atlantic(n,vector<int>(m,0));
       
       // perform DFS for pacific (top row and left column)
       for(int i=0;i<n;i++) DFS(mat,pacific,i,0);
       for(int j=0;j<m;j++) DFS(mat,pacific,0,j);
       
       // perform DFS for atlantic (bottom row and right column)
       for(int i=0;i<n;i++) DFS(mat,atlantic,i,m-1);
       for(int j=0;j<m;j++) DFS(mat,atlantic,n-1,j);
       
       int cnt = 0;
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(pacific[i][j] && atlantic[i][j]){
                   cnt++;
               }
           }
       }
       return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.countCoordinates(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends