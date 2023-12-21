from typing import List

class Solution:
    def maxMeetings(self, N : int, S : List[int], F : List[int]) -> List[int]:
        meeting = [[i+1, S[i], F[i]] for i in range(N)]
        meeting.sort(key = lambda i:i[2])
        temp, res = meeting[0], [meeting[0][0]]
        for i in meeting[1:]:
            if temp[2]<i[1]: temp, res = i, res+[i[0]]
        return sorted(res)
#{ 
 # Driver Code Starts
class IntArray:
    def __init__(self) -> None:
        pass
    def Input(self,n):
        arr=[int(i) for i in input().strip().split()]#array input
        return arr
    def Print(self,arr):
        for i in arr:
            print(i,end=" ")
        print()


if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        N = int(input())
        
        
        S=IntArray().Input(N)
        
        
        F=IntArray().Input(N)
        
        obj = Solution()
        res = obj.maxMeetings(N, S, F)
        
        IntArray().Print(res)
        

# } Driver Code Ends