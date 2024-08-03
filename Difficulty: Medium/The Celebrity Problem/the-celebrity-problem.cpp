//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n=mat.size();
        int cInd=-1;
        for(int i=0;i<n;i++){
            int flag=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==1) {flag=1;break;}
            }
            if(flag==0){
                cInd=i;
                break;
            }
        }
        if(cInd==-1) return -1;
        for(int c=0;c<n;c++){
            if(cInd!=c){
                if(mat[c][cInd]==0) return -1;
            }
        }
        return cInd;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends