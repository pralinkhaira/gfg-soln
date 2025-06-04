class Solution {
  public:
  int f(int i,int j,int k,string &s1,string &s2,string &s3,vector<vector<vector<int>>>&dp){
      if(i>=s1.size() || j>=s2.size() || k>=s3.size()){
          return 0;
      }
      if(dp[i][j][k]!=-1) return dp[i][j][k];
      int op1=f(i+1,j,k,s1,s2,s3,dp);
      int op2=f(i,j+1,k,s1,s2,s3,dp);
      int op3=f(i,j,k+1,s1,s2,s3,dp);
      int notTake=max(op1,max(op2,op3));
      int take=INT_MIN;
      if(s1[i]==s2[j] && s2[j]==s3[k]) take=f(i+1,j+1,k+1,s1,s2,s3,dp)+1;
      
      return dp[i][j][k]=max(take,notTake);
      
  }
    int lcsOf3(string& s1, string& s2, string& s3) {
        int m=s1.size(),n=s2.size(),o=s3.size();
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(o+1,-1)));
        return f(0,0,0,s1,s2,s3,dp);
        
    }
};