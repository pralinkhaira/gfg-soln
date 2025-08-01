class Solution:
    def countBalanced(self, arr):
        from collections import defaultdict
        seen=defaultdict(int)
        seen[0]=1
        pfs=[]
        ret=0
        for ix,w in enumerate(arr):
            bal=0
            for c in w:
                bal+=1 if c in 'aeiou' else -1
            pfs.append(bal)
            if ix>=1:
                pfs[ix]+=pfs[ix-1]
            ret+=seen[pfs[ix]]
            seen[pfs[ix]]+=1
        return ret