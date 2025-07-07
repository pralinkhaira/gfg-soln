class Solution:
    def nextLargerElement(self, arr):
        lth=len(arr)
        stk=[0]
        ret=[-1]*lth
        for ix in range(1,2*lth):
            while stk and arr[ix%lth]>arr[stk[-1]%lth]:
                ret[stk[-1]%lth]=arr[ix%lth]
                stk.pop()
            stk.append(ix%lth)
        return ret