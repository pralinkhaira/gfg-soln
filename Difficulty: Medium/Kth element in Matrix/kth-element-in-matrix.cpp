class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        
        int m=matrix.size();
        int n=m*m;
        int arr[n];
        int a=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
        {
            arr[a++]=matrix[i][j];
        }
            
        }
        sort(arr,arr+a);
        return arr[k-1];
    }
};