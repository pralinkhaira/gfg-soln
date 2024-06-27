//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isToeplitz(vector<vector<int>> &mat);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToeplitz(a);

        if (b == true)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

bool isToeplitz(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    
    for(int i=0;i<m;i++){
        int col = i, row = 0;
        int val = mat[row][col];
        while(col<m && row<n){
            //cout<<mat[row][col]<<" ";
            if(mat[row][col]!=val) return false;
            row++;
            col++;
        }
    }
    for(int i=0;i<n;i++){
        int row = i, col = 0;
        int val = mat[row][col];
        while(col<m && row<n){
            if(mat[row][col]!=val) return false;
            row++;
            col++;
        }
    }
    
    return true;
}