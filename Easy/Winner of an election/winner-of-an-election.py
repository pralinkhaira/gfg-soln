class Solution:
   def winner(self,arr,n):
        from collections import Counter
        return sorted(Counter(arr).items(), key=lambda x: (-x[1], x[0]))[0]
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    T=int(input())
    for _ in range(T):
        
        n=int(input())
        arr=input().strip().split()
        
        result = Solution().winner(arr,n)
        print(result[0],result[1])
# } Driver Code Ends