from collections import Counter
import math
class Solution:
    def findMajority(self, arr):
        sorted_arr=sorted(arr)
        n=len(sorted_arr)
        new=[]
        one_third=math.floor(n//3)
        result=Counter(sorted_arr)
        for key,value in result.items():
            if(value>one_third):
                new.append(key)
        return new