class Solution:
    def maxRectSum(self, mat):
        n = len(mat)
        m = len(mat[0])
        max_sum = float('-inf')

        for top in range(n):
            compressed = [0] * m
            for bottom in range(top, n):
                for col in range(m):
                    compressed[col] += mat[bottom][col]
                current_max = self.kadane(compressed)
                max_sum = max(max_sum, current_max)

        return max_sum

    def kadane(self, arr):
        max_current = max_global = arr[0]
        for num in arr[1:]:
            max_current = max(num, max_current + num)
            max_global = max(max_global, max_current)
        return max_global