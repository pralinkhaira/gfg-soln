from typing import List


from typing import List

def find(s, u):
    x = u
    while s[u] != u:
        u = s[u]
    s[x] = u
    return u

def funct_union(s, r, u, v):
    x = find(s, u)
    y = find(s, v)
    if x == y:
        return
    r[y] += r[x]
    s[x] = y


class Solution:
    def numberOfPairs(self, a : List[int], pairs : List[List[int]]) -> int:
        # code here
        n, p = a
        s = list(range(n))
        r = [1] * n
        
        for u, v in pairs:
            funct_union(s, r, u, v)
        
        ans = []
        for i in range(n):
            if s[i] == i:
                ans.append(r[i])
        
        n1 = n
        fans = (n1 * n1 - n1) // 2
        
        tans = 0
        for j in ans:
            tans += (j * j - j) // 2
        
        return fans - tans

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



class IntMatrix:
    def __init__(self) -> None:
        pass
    def Input(self,n,m):
        matrix=[]
        #matrix input
        for _ in range(n):
            matrix.append([int(i) for i in input().strip().split()])
        return matrix
    def Print(self,arr):
        for i in arr:
            for j in i:
                print(j,end=" ")
            print()


if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        a=IntArray().Input(2)
        
        
        pairs=IntMatrix().Input(a[1], a[1])
        
        obj = Solution()
        res = obj.numberOfPairs(a, pairs)
        
        print(res)
        

# } Driver Code Ends