class Solution:
    def minDifference(self, arr):
        def to_seconds(t):
            h, m, s = map(int, t.split(":"))
            return h * 3600 + m * 60 + s

        seconds = sorted(to_seconds(t) for t in arr)
        min_diff = float('inf')
        
        for i in range(1, len(seconds)):
            diff = seconds[i] - seconds[i - 1]
            min_diff = min(min_diff, diff)
        
        # Check wrap-around case
        wrap_around = 86400 - seconds[-1] + seconds[0]
        min_diff = min(min_diff, wrap_around)
        
        return min_diff