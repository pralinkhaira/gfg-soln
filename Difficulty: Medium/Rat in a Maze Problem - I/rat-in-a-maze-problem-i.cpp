//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution{
    void rec(vector<vector<int>> &mat, int i, int j, string s, vector<string> &ans, vector<vector<int>> &vis){
        int n=mat.size(),m=mat[0].size();
        if(i<0 || i>=n || j<0 || j>=m || !mat[i][j] || vis[i][j]) return;
        
        if(i==n-1 && j==m-1){
            ans.push_back(s);
            return;
        }
        vis[i][j]=1;
        
        s.push_back('L');
        rec(mat,i,j-1,s,ans,vis);
        s.pop_back();
        
        s.push_back('R');
        rec(mat,i,j+1,s,ans,vis);
        s.pop_back();
        
        s.push_back('U');
        rec(mat,i-1,j,s,ans,vis);
        s.pop_back();
        
        s.push_back('D');
        rec(mat,i+1,j,s,ans,vis);
        s.pop_back(); 
        
        vis[i][j]=0;
    }
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        int n=mat.size(),m=mat[0].size();
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int>(m,0));
        rec(mat,0,0,"",ans,vis);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends