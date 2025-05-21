class Solution {
  public:
    int kthSmallest(int m, int n, int k) {
        // There are numbers from 1 to m*n in the matrix
        // 1 is the top left and m*n will be the bottom right
        // We need to find the kth smallest element in the matrix
        // We do binary search over this range, and check for the mid how many elements in the matrix are smaller or equal to mid
        // To make this check optimised, we can use the fact that for ith row, elements will in the form of 1*i, 2*i, 3*i...., n*i
        // So, if mid/i >= n, it means mid is greater than or equal to all elements in the row
        // If count of total elements smaller than or equal to mid is greater than or equal to k, we update our ans variable and move to left side, else move to right side
        
        int low = 1;
        int high = m*n;
        int ans = m*n;
        while(low <= high){
            int mid = low + (high - low)/2;
            int count = 0; // Will store count of elements in the matrix smaller than or equal to mid 
            // We will find elements from each row
            // Rows and columns are 1-indexed
            for(int i = 1; i <= m; i++){
                count += min(mid/i, n); 
            }
            
            if(count >= k){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
