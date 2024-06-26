//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
        int ans=0, n=matrix.size(), m=matrix[0].size();
        vector<int>row={-1,1,0,0};
        vector<int>col={0,0,-1,1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    for(int x=0;x<4;x++){
                        int nrow=i+row[x], ncol=j+col[x];
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&matrix[nrow][ncol]==1){
                            ans++;
                        }
                    }
                }
            }
        }
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
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends