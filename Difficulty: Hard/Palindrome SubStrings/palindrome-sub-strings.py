class Solution:
    def countPS(self, s):
        # code here
        n=len(s)
        ans=0
        for i in range(n):
            for h in (i,i+1):
                l=i-1
                while l>=0 and h<n and s[l]==s[h]:
                    l-=1
                    h+=1
                    ans+=1
        return ans