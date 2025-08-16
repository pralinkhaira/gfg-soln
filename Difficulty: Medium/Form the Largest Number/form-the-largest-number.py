class Solution:

	def findLargest(self, arr):
	    # code here
	    import functools
        def cmp(a: str, b: str) -> int:
            ab = a+b
            ba = b+a
            if ab > ba:
                return -1
            else:
                return 1
        arr = sorted([str(e) for e in arr], key=functools.cmp_to_key(cmp))
        if arr[0] == '0':
            return "0"
        return "".join(arr)