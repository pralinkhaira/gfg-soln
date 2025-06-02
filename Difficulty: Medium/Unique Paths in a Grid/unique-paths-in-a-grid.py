class Solution:
    def uniquePaths(self, grid):
        #sam
        if grid[0][0]==1:
            return 0
        visited = [[False for _ in range(len(grid[0]))]for _ in range(len(grid))]
        dp = [[-1 for _ in range(len(grid[0]))]for _ in range(len(grid))]
        return self.dfs(grid,visited,0,0,0,dp)
    
    def dfs(self,grid,visited,r,c,count,dp):
        if r==len(grid)-1 and c==len(grid[0])-1:
            return 1
        
        visited[r][c] = True
        cnt = 0
        if dp[r][c] != -1:
            return dp[r][c]
        for dr,dc in [(1,0),(0,1)]:
            i,j = dr+r,dc+c
            if 0<=i<len(grid) and 0<=j<len(grid[0])and not visited[i][j] and grid[i][j]!=1:
                cnt += self.dfs(grid,visited,i,j,count,dp)
                
        visited[r][c] = False
        dp[r][c] = cnt
        return cnt