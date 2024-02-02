class Solution:
    # your task is to complete this function
    def atoi(self,s):
        # Code here
        
        sign=1
        res=0
        if s[0]=='-':
            sign=-1
            s=s[1:]
        
        for i in s:
            if '0'<=i<='9':
                res=res*10+(ord(i)-ord('0'))
            else:
                return -1
                
        return sign*res
#{ 
 # Driver Code Starts
#Initial template for Python

if __name__=='__main__':
    t=int(input())
    for i in range(t):
        string = input().strip();
        ob=Solution()
        print(ob.atoi(string))
# } Driver Code Ends