class Solution:
    def searchMatrix(self, mat, x):
        # code here
        import bisect
        for r in mat:
            if r[0] < r[-1]:
                i = bisect.bisect_left(r, x)
                if i < len(r) and r[i] == x:
                    return True
            else:
                lo, hi = 0, len(r)-1
                while lo <= hi:
                    mi = lo+(hi-lo)//2 
                    value = r[mi]
                    if value == x:
                        return True
                    am_big = value >= r[0]
                    x_big = x >= r[0]
                    if am_big == x_big:
                        if value < x:
                            lo = mi+1
                        else:
                            hi = mi-1
                    else:
                        if am_big:
                            lo = mi+1
                        else:
                            hi = mi -1
                if lo < len(r) and r[lo] == x:
                    return True
        return False