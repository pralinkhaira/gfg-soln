//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int c=1,r=1;
        for(int i=0;i<mat.size();i++){
            if(mat[i][0]==0) {c=0;
                break;
            }
        }
        for(int i=0;i<mat[0].size();i++){
            if(mat[0][i]==0) {r=0;
                break;
            }
        }
        for(int i=1;i<mat.size();i++){
            for(int j=1;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    mat[i][0]=0;
                    mat[0][j]=0;
                }
            }
        }
        for(int i=1;i<mat.size();i++){
            if(mat[i][0]==0){
                for(int j=1;j<mat[0].size();j++){
                    mat[i][j]=0;
                }
            }
        }
        for(int i=1;i<mat[0].size();i++){
            if(mat[0][i]==0){
                for(int j=1;j<mat.size();j++){
                    mat[j][i]=0;
                }
            }
        }
        if(r==0){
            for(int i=0;i<mat[0].size();i++){
                mat[0][i]=0;
            }
        }
        if(c==0){
            for(int i=0;i<mat.size();i++){
                mat[i][0]=0;
            }
        }
        return;
    }
    // 1 0 1
    // 0 0 1
    // 1 -1 1
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
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends