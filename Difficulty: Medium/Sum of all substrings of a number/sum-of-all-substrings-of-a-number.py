class Solution:
    #Function to find sum of all possible substrings of the given string.
    def sumSubstrings(self,s):
        
        # code here
        r=0
        n=len(s)
        t=0
        for i in range(n):
            val=int(s[i])
            t=val*(i+1)+10*t
            r=r+t
        return r