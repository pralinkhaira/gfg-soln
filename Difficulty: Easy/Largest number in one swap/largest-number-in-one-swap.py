class Solution:
    def largestSwap(self, s):
        #code here
        s = list(s)
        last = {ch: i for i, ch in enumerate(s)}  # last occurrence of each character
        
        for i in range(len(s)):
            for ch in reversed(sorted(last.keys())):
                if ch > s[i] and last[ch] > i:
                    # Perform swap
                    s[i], s[last[ch]] = s[last[ch]], s[i]
                    return ''.join(s)
        return ''.join(s)
        