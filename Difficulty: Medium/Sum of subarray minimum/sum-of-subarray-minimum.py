class Solution:
    def sumSubMins(self, arr):
        # Code here
        
        
        n = len(arr)
        
        stack =[]
        sumi = 0
     
        
        for i in range(n):
            
            count=1
            #print(count)
            while stack and arr[i]<=stack[-1][0]:
                #print(arr[i], stack[-1][0])
                count+=stack[-1][1]
                stack.pop(-1)
        
            stack.append((arr[i], count))
            
            for num, c in stack:
                sumi+=num*c

                
      
            
            
        
        return sumi