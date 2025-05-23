class Solution:
    def noOfWays(self, m,n,x):
        dp = [[0 for _ in range(x + 1)] for _ in range(n + 1)]
        dp[0][0] = 1

        for dice in range(1, n + 1):
            for target in range(1, x + 1):
                for face in range(1, m + 1):
                    if target - face >= 0:
                        dp[dice][target] += dp[dice - 1][target - face]
        return dp[n][x]