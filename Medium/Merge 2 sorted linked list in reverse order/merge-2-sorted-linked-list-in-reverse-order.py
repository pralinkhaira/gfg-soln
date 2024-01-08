#User function Template for python3
'''
class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
'''
def reverse(dummy):
    temp = dummy
    prev = None
    while temp:
        front = temp.next
        temp.next = prev
        prev = temp
        temp = front
    return prev
class Solution:
    def mergeResult(self, h1, h2):
        #return head of merged list
        if not h1: return reverse(h2)
        if not h2: return reverse(h1)
        if h1.data<h2.data:
            l1 = h1
            l2 = h2
        else:
            l1 = h2
            l2 = h1
        dummy = l1
        while l1 and l2:
            prev = None
            while l1 and l1.data<=l2.data:
                prev = l1
                l1 = l1.next
            prev.next = l2
            l1, l2 = l2, l1
        return reverse(dummy)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

class Llist:
    def __init__(self):
        self.head=None
    
    def insert(self,data,tail):
        node=Node(data)
        
        if not self.head:
            self.head=node
            return node
        
        tail.next=node
        return node
        

def printList(head):
    while head:
        print(head.data,end=' ')
        head=head.next
        
if __name__ == '__main__':
    t=int(input())
    
    for tcs in range(t):
        
        n1,n2=[int(x) for x in input().split()]
        
        arr1=[int(x) for x in input().split()]
        ll1=Llist()
        tail=None
        for nodeData in arr1:
            tail=ll1.insert(nodeData,tail)
            
            
        arr2=[int(x) for x in input().split()]
        ll2=Llist()
        tail=None
        for nodeData in arr2:
            tail=ll2.insert(nodeData,tail)
        
        
        ob = Solution()
        resHead=ob.mergeResult(ll1.head,ll2.head)
        printList(resHead)
        print()
        
    
    
# } Driver Code Ends