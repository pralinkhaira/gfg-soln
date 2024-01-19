from collections import defaultdict
class Solution:
    def kTop(self,a, N, K):
        #code here.
        sol=[]
        cnt=defaultdict(int)
        lst=[]
        for i,j in enumerate(a):
            cnt[j]+=1
            if cnt[j]==1:
                lst.append(j)
            lst.sort(key=lambda x:(-cnt[x],x))
            sol.append(lst[:min(K,i+1)])
        return sol
#{ 
 # Driver Code Starts


t=int(input())
for _ in range(0,t):
    n,k=list(map(int,input().split()))
    a=list(map(int,input().split()))
    ob = Solution()
    ans=ob.kTop(a,n,k)
    for line in ans:
        print(*line)



# } Driver Code Ends