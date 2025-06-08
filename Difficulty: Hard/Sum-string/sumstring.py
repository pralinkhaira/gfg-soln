class Solution:
    def isSumString (self, s):
        lth=len(s)
        def dfs(prv1,prv2,sta):
            nonlocal s,lth
            if sta>=lth:
                return True
            if s[sta]=='0':
                return False
            for sto in range(sta+1,lth+1):
                if int(s[sta:sto])==prv1+prv2:
                    if dfs(prv2,int(s[sta:sto]),sto):
                        return True
            return False
        for sta in range(1,lth-1):
            for sto in range(sta+1,lth):
                prv1=int(s[:sta])
                if s[sta]=='0':
                    continue
                prv2=int(s[sta:sto])
                if dfs(prv1,prv2,sto):
                    return True
        return False

