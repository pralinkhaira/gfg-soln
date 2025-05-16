class Solution:
    def findSmallestRange(self, arr):
        # code here
        from collections import Counter
        
        n = len(arr)
        col = []
        for i, r in enumerate(arr):
            for e in r:
                col.append((e, i))
        col.sort()
        
        cnt = Counter()
        
        left = 0
        ret = (col[0][0], col[-1][0])
        for i, (e, t) in enumerate(col):

            cnt[t] += 1
            while len(cnt) >= n and left <= i:
                x = col[left][0]
                y = col[i][0]
                if y - x < ret[1] - ret[0]:
                    ret = (x, y)
                left_idx = col[left][1]
                cnt[left_idx] -= 1
                if cnt[left_idx] == 0:
                    cnt.pop(left_idx)
                left += 1
        return ret
#{ 
 # Driver Code Starts
# Initial Template for Python 3

t = int(input())
for _ in range(t):
    n = int(input())
    k = int(input())
    arr = []
    for _ in range(k):
        arr.append(list(map(int, input().strip().split())))
    r = Solution().findSmallestRange(arr)
    print(r[0], r[1])
    print("~")

# } Driver Code Ends