from bisect import bisect_left

class Solution:
    def nonLisMaxSum(self, arr):
        # code here
        n = len(arr)
        parent = [-1] * n  # Stores the previous index in the LIS
        dp = []            # Holds the indices of potential LIS
        pos = [0] * n      # pos[i] = index of the LIS ending at i

        for i in range(n):
            # Find the location where arr[i] can be inserted in dp
            idx = bisect_left([arr[j] for j in dp], arr[i])

            if idx < len(dp):
                dp[idx] = i
            else:
                dp.append(i)

            pos[i] = idx
            if idx > 0:
                parent[i] = dp[idx - 1]  # Link to previous element in LIS

        # Now reconstruct LIS using parent array
        lis_sum = 0
        lis_len = len(dp)
        k = -1

        # Find the last index where LIS ends (has max pos value)
        for i in range(n - 1, -1, -1):
            if pos[i] == lis_len - 1:
                k = i
                break

        while k != -1:
            lis_sum += arr[k]
            k = parent[k]

        return sum(arr) - lis_sum