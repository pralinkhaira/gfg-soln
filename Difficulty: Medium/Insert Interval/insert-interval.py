class Solution:
    def insertInterval(self, intervals, newInterval):
        # Code here
        n=len(intervals)
        i=0
        op=[]
        while i<n and intervals[i][1]<newInterval[0]:
            op.append(intervals[i])
            i+=1
        
        while i<n and intervals[i][0]<=newInterval[1]:
            newInterval[0]=min(intervals[i][0],newInterval[0])
            newInterval[1]=max(intervals[i][1],newInterval[1])
            i+=1
        op.append(newInterval)
        while i<n:
            op.append(intervals[i])
            i+=1
        return op