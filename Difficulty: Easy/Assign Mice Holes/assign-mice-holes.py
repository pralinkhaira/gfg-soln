class Solution:
    def assignHole(self, mices, holes):
        # code here
        m=0
        mices.sort()
        holes.sort()
        for i in range(len(holes)):
            m=max(m,abs((holes[i]-mices[i])))
        return (m);
        