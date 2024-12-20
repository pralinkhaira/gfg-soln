//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        vector<int>ans;
        int t=0,l=0,r=matrix[0].size()-1,b=matrix.size()-1;
        while(t<=b && l<=r){
            for(int i=l;i<=r;i++){
                ans.push_back(matrix[t][i]);
            }
            t++;
            for(int i=t;i<=b;i++){
                ans.push_back(matrix[i][r]);
            }
            r--;
            if(t<=b){
                for(int i=r;i>=l;i--){
                    ans.push_back(matrix[b][i]);
                }
                b--;
                if(l<=r){
                    for(int i=b;i>=t;i--){
                        ans.push_back(matrix[i][l]);
                    }
                    l++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends