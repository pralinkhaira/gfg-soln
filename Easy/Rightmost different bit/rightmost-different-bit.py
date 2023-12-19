#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math




    
# } Driver Code Ends
#User function Template for python3

class Solution:
    
    #Function to find the first position with different bits.
    def posOfRightMostDiffBit(self,m,n):
        #Your code here
          # Find the XOR of m and n
        xor_result = m ^ n
        
        # If m and n are the same, return -1
        if xor_result == 0:
            return -1
        
        # Find the position of the rightmost set bit
        position = 1
        while xor_result:
            # Check if the current bit is set (i.e., equals 1)
            if xor_result & 1:
                return position
            # Move to the next bit
            xor_result >>= 1
            position += 1
        
        return position

#{ 
 # Driver Code Starts.
    
def main():
    
    T=int(input())
    
    while(T>0):
        
        
        mn=[int(x) for x in input().strip().split()]
        m=mn[0]
        n=mn[1]
        ob=Solution()
        print(math.floor(ob.posOfRightMostDiffBit(m,n)))
        
        
        
        
        T-=1
    
    




if __name__=="__main__":
    main()
# } Driver Code Ends