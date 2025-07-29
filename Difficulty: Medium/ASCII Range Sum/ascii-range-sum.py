from collections import defaultdict

class Solution:
    def asciirange(self, s: str):
        dic = defaultdict(list)
        prefix = [0] * (len(s) + 1)

        for i, ch in enumerate(s):
            dic[ch].append(i)
            prefix[i + 1] = prefix[i] + ord(ch)

        ans = [
            prefix[j[-1]] - prefix[j[0] + 1]
            for j in dic.values()
            if len(j) > 1 and prefix[j[-1]] - prefix[j[0] + 1] != 0
        ]
        return sorted(ans)