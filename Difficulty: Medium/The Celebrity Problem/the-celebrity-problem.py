class Solution:
    def celebrity(self, mat):
        # code here
        left=0
        right=len(mat)-1
        while left<right:
            if mat[left][right]==mat[right][left]!=1:
                left+=1
                right-=1
                
            elif mat[left][right]==1:
                left+=1
                
            elif mat[right][left]==1:
                right-=1
        for i in range(len(mat)):
            if mat[i][left]==0:
                return -1
        for i in range(len(mat[0])):
            if left!=i and mat[left][i]==1:
                return -1
        return left