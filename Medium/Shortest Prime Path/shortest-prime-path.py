#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3
from collections import deque
import math
class Solution:
    def solve (self,Num1,Num2):
        #code here
        num1=str(Num1)
        num2=str(Num2)
        
        def isprime(num):
            for i in range(2,int(math.sqrt(num))+1):
                if num%i==0:
                    return False
            return True
        
        ans=0
        q=deque()
        q.append([num1,0])
        vis={num1}
        while q:
            p,cnt=q.pop()
            if p==num2:
                return cnt
            for i in range(4):
                if i!=0:
                    s1=p[:i]
                    s2=p[i+1:]
                    s=s1+str(0)+s2
                    if s not in vis and isprime(int(s)):
                        q.appendleft([s,cnt+1])
                        vis.add(s)
                for j in range(1,10):
                    s1=p[:i]
                    s2=p[i+1:]
                    s=s1+str(j)+s2
                    if s not in vis and isprime(int(s)):
                        q.appendleft([s,cnt+1])
                        vis.add(s)
        return 0

#{ 
 # Driver Code Starts.
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        Num1,Num2=map(int,input().split())
        ob = Solution()
        print(ob.solve(Num1,Num2))
# } Driver Code Ends