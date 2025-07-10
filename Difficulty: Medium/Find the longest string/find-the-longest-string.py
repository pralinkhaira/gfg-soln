class Solution():
    def longestString(self, words):
        # code here
        class Trie:
            def __init__(self):
                self.arr=[None for _ in range(26)]
                self.bo=False
        root=Trie()
        def insert(word):
            node=root
            for i in word:
                ind=ord(i)-ord('a')
                if not node.arr[ind]:
                    node.arr[ind]=Trie()
                node=node.arr[ind]
            node.bo=True
        for w in words:
            insert(w)
        def search(word,prefix=""):
            node=root
            for i in word:
                bol=node.arr[ord(i)-ord('a')]
                if not bol.bo:
                    return False
                node=node.arr[ord(i)-ord('a')]
            return True
                    
        maxi=-1
        op=""
        for w in words:
            if len(w)>maxi:
                if search(w):
                    maxi=len(w)
                    op=w
            if len(w)==maxi:
                if search(w):
                    maxi=len(w)
                    if op>w:
                        op=w
        return op