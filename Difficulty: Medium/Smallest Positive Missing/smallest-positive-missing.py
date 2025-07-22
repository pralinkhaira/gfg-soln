class Solution:
    def missingNumber(self, arr):
        arr = set(arr)
        i = 1
        while i in arr:
            i += 1
        return i     