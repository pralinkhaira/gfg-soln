class Solution {
  public:
  int fib(int n,vector<int>&dp1){
      if(n==0 || n==1) return n;
      
      
      if(dp1[n]!=-1) return dp1[n];
      return dp1[n]=fib(n-1,dp1)+fib(n-2,dp1);
  }
  
  int f(int n,vector<int>&dp,vector<int>&dp1){
      if(n==1) return 0;
      if(n==2) return 1;
      if(dp[n]!=-1) return dp[n];
      return dp[n]=f(n-1,dp,dp1)*2+fib(n-1,dp1);
  }
    int countConsec(int n) {
        vector<int>dp(n+1,-1);
        vector<int>dp1(n+1,-1);
        // code here
        return f(n,dp,dp1);
    }
};