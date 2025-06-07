class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        // Code here.
        int n=a1.size();
        unordered_map<int, int>mpp;
        int sum=0;
        int maxi=0;
        
        mpp[0]=-1;
        
        for(int i=0; i<n; i++){
            sum+=(a1[i]-a2[i]);
            if(mpp.find(sum)!=mpp.end()){
                maxi=max(maxi, i-mpp[sum]);
            }else mpp[sum]=i;
        }
        
        return maxi;
    }
};