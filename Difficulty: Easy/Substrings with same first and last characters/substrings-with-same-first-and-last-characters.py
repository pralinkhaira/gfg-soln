class Solution:
	def countSubstring(self, s):
		# code here
		freq = [0]*26
		ans = 0
		for c in s:
		    freq[ord(c)-ord('a')] = freq[ord(c)-ord('a')]+1
		    ans += freq[ord(c)-ord('a')]
        return ans
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        s = input()

        ob = Solution()
        answer = ob.countSubstring(s)

        print(answer)
        print("~")

# } Driver Code Ends