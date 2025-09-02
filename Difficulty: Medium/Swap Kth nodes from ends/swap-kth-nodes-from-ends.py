'''
class Node:
    def __init__(self, x):
        self.data = x
        self.next = None
'''
class Solution:
    def swapKth(self, head, k):
        # Finding the length of the Linked LIst
        temp = head
        length = 0
        
        while(temp):
            length+=1
            temp = temp.next
        
        # Edge Case : Not possible to swap Nodes
        if k>length:
            return head
            
        # Finding the K-th Node from the start
        first = head
        
        cnt1 = 1
        
        while(cnt1!=k):
            first = first.next
            cnt1+=1
        
        # Finding the K-th Node from the End
        last = head
        
        cnt2 = 0
        
        while(cnt2 != (length-k)):
            last = last.next
            cnt2+=1
        
        # Swapping their Values
        first.data,last.data = last.data,first.data
        
        # Thats it - return Head of manipulated LinkedList
        return head