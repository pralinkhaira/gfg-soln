class Solution:
    def subarraySum(self, arr):
        # code here 
        l=len(arr)
        s=0
        for i in range(len(arr)):
            val=(arr[i]*(l-i))
            s=s+val+(val*i)
        return s