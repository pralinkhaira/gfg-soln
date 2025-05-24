class Solution:
    def pythagoreanTriplet(self, arr):
        from collections import Counter
        
        freq = Counter(arr)
        nums = sorted(set(arr))
        squares = {x: x * x for x in nums}
        square_set = set(v for v in squares.values())

        for i in range(len(nums)):
            for j in range(i, len(nums)):
                a, b = nums[i], nums[j]
                c2 = squares[a] + squares[b]
                c = int(c2 ** 0.5)
                if c * c == c2 and c in freq:
                    # handle duplicates properly
                    if c != a and c != b:
                        return True
                    if c == a and freq[a] > 1:
                        return True
                    if c == b and freq[b] > 1:
                        return True
                    if a == b == c and freq[a] > 2:
                        return True
        return False
