class Solution:
    def balanceSums(self, mat):
        # code here
        rows=[]
        cols=[]
        for i in mat:
            rows.append(sum(i))   # sum of individual rows
            
        m=len(mat[0])
        n=len(mat)
        for i in range(m):
            s=0
            for j in range(n):
              s+=mat[j][i]
            cols.append(s)         #sum of individual cols
            
        mx=max(rows+cols)          # sum of elements in every row and every column is equal to max value
        
        for i in range(n):
            rows[i]=mx-rows[i]   # how much differ with max value
        for j in range(m):
            cols[j]=mx-cols[j] 
            
        cnt=0
        for i in range(n):
            for j in range(m):
                val=min(rows[i],cols[j])  #minimium value should be add at i,j
                if val!=0:
                    cnt+=val       #Count operations
                mat[i][j]+=val 
                rows[i]-=val 
                cols[j]-=val 
        return cnt