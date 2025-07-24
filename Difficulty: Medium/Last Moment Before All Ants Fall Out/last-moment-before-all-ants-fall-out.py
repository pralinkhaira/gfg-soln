class Solution:
    def getLastMoment(self, n, left, right):
        return max(max(left) if left else 0, max(map(lambda x: n - x, right)) if right else 0)