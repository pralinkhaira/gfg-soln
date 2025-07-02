class Solution:
    def totalElements(self, arr):
        freq = {}  # Dictionary to count frequency of elements
        ans = 0    # To store the maximum length of valid subarray
        left = 0   # Left pointer of the sliding window

        for right in range(len(arr)):
            freq[arr[right]] = freq.get(arr[right], 0) + 1

            # If more than 2 distinct elements, shrink from the left
            while len(freq) > 2:
                freq[arr[left]] -= 1
                if freq[arr[left]] == 0:
                    del freq[arr[left]]
                left += 1

            # Update the answer with the max length found
            ans = max(ans, right - left + 1)

        return ans
