class Solution:
    def repeatedRows(self, arr, m ,n):
        #code here
        seen_rows = set()
        duplicate_rows = []
    
        for i in range(m):
            row_data = tuple(arr[i])
            if row_data in seen_rows:
                duplicate_rows.append(i)
            else:
                seen_rows.add(row_data)
    
        return duplicate_rows
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n, m = list(map(int, input().strip().split()))
        
        arr = []
        for i in range(n):
            nums = list(map(int, input().strip().split()))
            arr.append(nums)
        ob = Solution()
        ans = ob.repeatedRows(arr, n, m)
        
        for x in ans:
            print(x, end=" ")
            
        print()
        tc -= 1

# } Driver Code Ends