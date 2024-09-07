#User function Template for python3
class Solution:
    def findNth(self, N: int) -> int:
        result = 0
        multiplier = 1

        while N > 0:
            result += (N % 9) * multiplier
            N //= 9
            multiplier *= 10

        return result






#{ 
 # Driver Code Starts
#Initial Template for Python 3

t = int(input())
for i in range(0, t):
    n = int(input())
    obj = Solution()
    s = obj.findNth(n)
    print(s)

# } Driver Code Ends