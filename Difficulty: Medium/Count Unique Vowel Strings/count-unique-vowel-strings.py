from collections import defaultdict
import math
class Solution:
    def vowelCount(self, s):
        #code here
        vowel = set('aeiou')
        hm = defaultdict(int)
        for i in s:
            if i in vowel:
                hm[i]+=1
        if not hm:
            return 0
        fact = 1
        for i,j in hm.items():
            fact*=j
        fact*=math.factorial(len(hm))
        return fact