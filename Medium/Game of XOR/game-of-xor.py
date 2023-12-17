class Solution:
    def gameOfXor(self, N , A):
        # code here
        if N & 1 == 0:
            return 0
        result = 0
        for i in range(N):
            if ((N - i) * (i + 1)) & 1 == 1:
                result ^= A[i]
        return result 
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        N=int(input())
        A=list(map(int,input().split()))
        
        ob = Solution()
        print(ob.gameOfXor(N,A))
# } Driver Code Ends