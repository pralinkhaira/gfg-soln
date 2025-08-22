class Solution {
  public:
    int count(vector<vector<int>>mat,int mid){
        int count=0;
        for(int i=0;i<mat.size();i++){
            count+=upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
        }
        return count;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int r=mat.size();
        int c=mat[0].size();
        int mini=mat[0][0];
        int maxi=mat[0][c-1];
        for(int i=0;i<r;i++){
            mini=min(mini,mat[i][0]);
            maxi=max(maxi,mat[i][c-1]);
        }
        int ans=-1;
        int low=mini;
        int high=maxi;
        int medianval=(r*c)/2;
        //atleast medianval+1 hona chahiye.
        while(low<=high){
            int mid=low+(high-low)/2;
            int smallerequals=count(mat,mid);
            if(smallerequals<medianval+1){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};