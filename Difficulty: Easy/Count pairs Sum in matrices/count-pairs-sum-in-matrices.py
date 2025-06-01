class Solution:
	def countPairs(self, mat1, mat2, x):
		# code here
		sol = 0
		m1 = [element for row in mat1 for element in row]
		m2 = [element for row in mat2 for element in row]
		p1 = 0
		p2 = len(m2)-1
		while(p1 < len(m1) and p2 >= 0):
		    if m1[p1]+m2[p2] == x:
		        sol+=1
		        p1+=1
		        p2-=1
		    elif m1[p1]+m2[p2] < x:
		        p1+=1
		    else:
		        p2-=1
		return(sol)