class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
 
        
class Solution:
    def sortedInsert(self, head, data):
        new_node = Node(data)

        if not head:
            new_node.next = new_node
            return new_node

        curr = head

        if data < head.data:
            while curr.next != head:
                curr = curr.next
            curr.next = new_node
            new_node.next = head
            return new_node

        while curr.next != head and curr.next.data < data:
            curr = curr.next

        new_node.next = curr.next
        curr.next = new_node
        return head