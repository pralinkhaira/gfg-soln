from collections import Counter
class Solution:
    def findGreater(self, arr):
        # code here
        d = Counter(arr)
        ans = []
        st=[]
        for i in range(len(arr)-1,-1,-1):
            while len(st) and d[arr[i]]>=d[st[-1]]:
                st.pop()
            if len(st):
                ans.append(st[-1])
            else:
                ans.append(-1)
            st.append(arr[i])
        ans.reverse()
        return ans