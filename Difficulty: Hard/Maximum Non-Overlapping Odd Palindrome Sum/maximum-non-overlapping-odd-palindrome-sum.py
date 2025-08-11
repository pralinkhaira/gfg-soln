import heapq
class Solution:
    def maxSum(self, s: str) -> int:
        n = len(s)
        if n < 2:
            return 0
        # ---------- Manacher for odd-length palindromes ----------
        # d1[i] = max k such that s[i-k+1 .. i+k-1] is palindrome (length = 2*k-1)
        d1 = [0] * n
        l, r = 0, -1
        for i in range(n):
            k = 1 if i > r else min(d1[l + r - i], r - i + 1)
            while i - k >= 0 and i + k < n and s[i - k] == s[i + k]:
                k += 1
            d1[i] = k
            if i + k - 1 > r:
                l = i - k + 1
                r = i + k - 1
        # prepare centers info: (start_i, i, right_end_i)
        centers = []
        for i in range(n):
            k = d1[i]
            start_i = i - k + 1
            end_i = i + k - 1
            centers.append((start_i, i, end_i))
        # ---------- left_best_end[end] ----------
        # scan end from left to right, maintain min-heap keyed by center index i
        left_best_end = [0] * n
        heap = []  # (i, right_end)
        for end in range(n):
            # add center with index == end (centers stored by index i)
            i = end
            _, ci, right_end = centers[i]
            # push (i, right_end)
            heapq.heappush(heap, (ci, right_end))
            # remove centers that no longer cover this end (right_end < end)
            while heap and heap[0][1] < end:
                heapq.heappop(heap)
            if heap:
                min_i = heap[0][0]
                left_best_end[end] = 2 * (end - min_i) + 1
            else:
                left_best_end[end] = 0
        # ---------- right_best_start[start] ----------
        # we want for each start the center with largest i that covers start.
        # sort centers by start_i ascending and sweep start from 0..n-1
        centers_by_start = sorted(centers, key=lambda x: x[0])
        right_best_start = [0] * n
        heap2 = []  # max-heap by i -> store as (-i, right_end)
        idx = 0
        for start in range(n):
            # add all centers whose start_i <= start
            while idx < n and centers_by_start[idx][0] <= start:
                st_i, ci, right_end = centers_by_start[idx]
                heapq.heappush(heap2, (-ci, right_end))
                idx += 1
            # remove centers that no longer cover this start (right_end < start)
            while heap2 and heap2[0][1] < start:
                heapq.heappop(heap2)
            if heap2:
                max_i = -heap2[0][0]
                right_best_start[start] = 2 * (max_i - start) + 1
            else:
                right_best_start[start] = 0
        # ---------- prefix/suffix maximum arrays ----------
        left_max = [0] * n
        left_max[0] = left_best_end[0]
        for i in range(1, n):
            left_max[i] = max(left_max[i - 1], left_best_end[i])
        right_max = [0] * n
        right_max[n - 1] = right_best_start[n - 1]
        for i in range(n - 2, -1, -1):
            right_max[i] = max(right_max[i + 1], right_best_start[i])
        # ---------- combine by cutting between pos and pos+1 ----------
        ans = 0
        for cut in range(n - 1):
            ans = max(ans, left_max[cut] + right_max[cut + 1])
        return ans