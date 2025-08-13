from heapq import *
class Solution:
    def minSoldiers(self, arr, k):
        c=0
        for i in arr:
            if i%k!=0:
                c+=1
        n=len(arr)
        if c<n//2:
            return 0
        else:
            ans=0
            heap=[]
            for i in arr:
                if i%k!=0:
                    diff=i%k
                    heappush(heap,[k-diff,i])
            non=len(arr)-c
            if n%2:
                non-=1
            while heap and non<n//2:
                a=heappop(heap)
                ans+=a[0]
                non+=1
            return ans