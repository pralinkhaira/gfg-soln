class Solution {
  public:
    void solve(int strt , int sum , int target, int size , vector<int>&temp , vector<vector<int>>&ans){
      
        if(temp.size() == size){
            if(sum == target){
                ans.push_back(temp);
            }
            return;
        }
        
        for(int i = strt ; i <= 9 ;i++ ){
            if(sum > target) break;
            sum += i ;
            temp.push_back(i);
            
            solve(i+1,sum,target,size,temp,ans); 
            
            temp.pop_back();
            sum-=i;
        }
        
    }
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<vector<int>>ans;
        vector<int>temp;
        solve(1,0,n,k,temp,ans);
        return ans;
    }
};
