//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        
        vector<int> path;
        
        int x=0,y=0, left=0,right=matrix[0].size()-1,up=0,down=matrix.size()-1;
        
        while(path.size()<(matrix[0].size()*matrix.size())){
            
            while(y<=right){
                path.push_back(matrix[x][y++]);
            }
            up++;
            y--;
            x++;
            if(up>down)
                break;
                
            while(x<=down){
                path.push_back(matrix[x++][y]);
            }
            right--;
            x--;
            y--;
            
            if(left>right)
                break;
                
            while(y>=left){
                path.push_back(matrix[x][y--]);
            }
            down--;
            y++;
            x--;
            if(up>down)
                break;
                
            while(x>=up){
                path.push_back(matrix[x--][y]);
            }
            x++;
            left++;
             if(left>right)
                break;
                
            y++;
            
        }
        return path;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends