class Solution:
    def Maximize(self, arr): 
        # Complete the function
        arr.sort()
        ans = 0
        for i,j in enumerate(arr):
            ans += (i*j)%1000000007
        return ans%1000000007
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        A = list(map(int, input().strip().split()))
        # k = int(input())
        ob = Solution()
        print(ob.Maximize(A))

# } Driver Code Ends