class Solution:
    def lcmTriplets(self, n):
        if n < 3:
            return n
        if n % 2:
            return n * (n - 1) * (n - 2)
        if n % 3:
            return n * (n - 1) * (n - 3)
        return (n - 1) * (n - 2) * (n - 3)
