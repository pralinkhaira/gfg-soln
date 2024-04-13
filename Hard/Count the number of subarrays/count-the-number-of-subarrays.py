#User function Template for python3
class Solution:
    def countSubarray(self, N, A, L, R):
        def countSubarraysWithSumLessThanOrEqual(arr, k):
            count = 0
            prefix_sum = 0
            start = 0
            for end in range(len(arr)):
                prefix_sum += arr[end]
                while prefix_sum > k:
                    prefix_sum -= arr[start]
                    start += 1
                count += (end - start + 1)
            return count

        return countSubarraysWithSumLessThanOrEqual(A, R) - countSubarraysWithSumLessThanOrEqual(A, L - 1)



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        N,L,R = map(int,input().strip().split())
        A = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.countSubarray(N, A, L, R)
        print(ans)

# } Driver Code Ends