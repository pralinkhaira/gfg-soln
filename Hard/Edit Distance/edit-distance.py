class Solution:
    def editDistance(self, s, t):
        # Code here
        
        m = len(s)
        n = len(t)
        dp = [[-1 for j in range(n+1)] for i in range(m+1)]
        return self.ed(s,t,m,n,dp)
        
    def ed(self,s,t,m,n,dp):
        if m == 0 and n == 0:
            return 0
        if m == 0:
            return n
        if n == 0:
            return m
        if dp[m][n] != -1:
           return dp[m][n]
        if s[m-1] == t[n-1]:
            dp[m][n] = self.ed(s,t,m-1,n-1, dp)
            return dp[m][n]
        else:
            dp[m][n]=1+min(self.ed(s,t,m-1,n,dp), self.ed(s,t,m,n-1,dp), self.ed(s,t,m-1,n-1,dp))
            return dp[m][n]

#{ 
 # Driver Code Starts
if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		s, t = input().split()
		ob = Solution();
		ans = ob.editDistance(s, t)
		print(ans)
# } Driver Code Ends