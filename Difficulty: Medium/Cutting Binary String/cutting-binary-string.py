class Solution:
    def cuts(self, s):
        # code here
        n = len(s)

        # Precompute powers of 5 up to length 30
        powers_of_5 = set()
        power = 1
        while True:
            binary = bin(power)[2:]
            if len(binary) > n:
                break
            powers_of_5.add(binary)
            power *= 5

        # Initialize dp array
        dp = [float('inf')] * (n + 1)
        dp[0] = 0  # base case: empty string needs 0 cuts

        for i in range(1, n + 1):
            # Only consider substrings with length <= i
            for j in range(i - 1, -1, -1):
                if s[j] == '0':
                    continue  # skip substrings with leading 0s
                if s[j:i] in powers_of_5:
                    dp[i] = min(dp[i], dp[j] + 1)

        return dp[n] if dp[n] != float('inf') else -1
