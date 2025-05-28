class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        const int n = mat.size(), m = mat[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int twos = 0;
                for(int k = 0; k < m; k++) {
                    if(mat[i][k] == 1 && mat[j][k] == 1) twos++;
                }
                if(twos >= 2) return true;
            }
        }
        return false;
    }
};