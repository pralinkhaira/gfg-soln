'''
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
'''

class Solution:
    def findPreSuc(self, root, key):
        # Initialize predecessor and successor as None
        ans = [None, None]

        while root:
            if root.data < key:
                # Possible predecessor
                ans[0] = root
                root = root.right
            elif root.data > key:
                # Possible successor
                ans[1] = root
                root = root.left
            else:
                # Exact node found
                if root.left:
                    temp = root.left
                    # Rightmost node in left subtree => predecessor
                    while temp.right:
                        temp = temp.right
                    ans[0] = temp

                if root.right:
                    temp = root.right
                    # Leftmost node in right subtree => successor
                    while temp.left:
                        temp = temp.left
                    ans[1] = temp
                break
        
        return ans  # [predecessor, successor]



#{ 
 # Driver Code Starts
import queue


# BST Node
class Node:

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def buildTree(ip):
    # Corner Case
    if len(ip) == 0 or ip[0] == 'N':
        return None

    # Create the root of the tree
    root = Node(int(ip[0]))

    # Push the root to the queue
    q = queue.Queue()
    q.put(root)

    # Starting from the second element
    i = 1
    while not q.empty() and i < len(ip):
        # Get and remove the front of the queue
        currNode = q.get()

        # Get the current node's value from the string
        currVal = ip[i]

        # If the left child is not null
        if currVal != "N":
            # Create the left child for the current node
            currNode.left = Node(int(currVal))

            # Push it to the queue
            q.put(currNode.left)

        # For the right child
        i += 1
        if i >= len(ip):
            break
        currVal = ip[i]

        # If the right child is not null
        if currVal != "N":
            # Create the right child for the current node
            currNode.right = Node(int(currVal))

            # Push it to the queue
            q.put(currNode.right)

        i += 1

    return root


# Driver program to test above functions
t = int(input())
for _ in range(t):
    s = input()
    root = buildTree(s.split())
    key = int(input())

    ob = Solution()
    result = ob.findPreSuc(root, key)
    pre, suc = result[0], result[1]

    if pre is not None:
        print(pre.data, end=" ")
    else:
        print(-1, end=" ")

    if suc is not None:
        print(suc.data)
    else:
        print(-1)
    print("~")

# } Driver Code Ends