class Solution
{
    int min_sprinklers(int bulbs[], int n)
    {
        n = bulbs.length;
        int[] dp = new int[n + 1];
        Arrays.fill(dp, n + 1);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            // we can only enlighten if bulbs[i]>=0
            if (bulbs[i] >= 0) {
                int leftMostPointOfStreetEnlightenedByCurrentBulb = 1 + Math.max(i - bulbs[i], 0); // +1 since dp.length = n+1
                int rightMostPointOfStreetEnlightenedByCurrentBulb = 1 + Math.min(i + bulbs[i], n - 1);
                for (int j = leftMostPointOfStreetEnlightenedByCurrentBulb; j <= rightMostPointOfStreetEnlightenedByCurrentBulb; ++j) {
                    dp[j] = Math.min(dp[j], dp[Math.max(0, i - bulbs[i])] + 1);
                }
            }
        }
        return dp[n] < n + 1 ? dp[n] : -1;
    
    }
}
