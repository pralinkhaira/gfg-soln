class Solution:
    def dfs(self, graph, i, rank, res, prev_rank, n):
        # Increment the rank of the current node
        rank[i] = prev_rank + 1
        # Initialize variable to track the minimum rank in the subtree
        t = float('inf')

        # Traverse the neighbors of the current node
        for nbr in graph[i]:
            if rank[nbr] == -1:
                # If the neighbor is not visited, perform DFS
                k = self.dfs(graph, nbr, rank, res, prev_rank + 1, n)
                # Check for critical connection, and update the minimum rank
                if k > rank[i]:
                    res.append([min(i, nbr), max(i, nbr)])
                t = min(t, k)
            elif rank[nbr] == n + 1:
                continue
            elif rank[nbr] != prev_rank:
                # Update the minimum rank based on the neighbor's rank
                t = min(t, rank[nbr])
        
        # Set the rank of the current node to n + 1 (indicating it has been visited)
        rank[i] = n + 1
        return t

    def criticalConnections(self, v, adj):
        # Initialize the result list to store critical connections
        res = []
        # Initialize rank array with -1, indicating unvisited nodes
        rank = [-1] * v

        # Perform DFS starting from the first node (node 0)
        k = self.dfs(adj, 0, rank, res, 0, v)
        
        # Sort the result list for a well-organized output
        res.sort()
        return res
#{ 
 # Driver Code Starts
#Initial Template for Python 3

import sys
sys.setrecursionlimit(10**6)

if __name__ == '__main__':

	T=int(input())
	for i in range(T):
		V, E = map(int, input().split())
		adj = [[] for i in range(V)]
		for _ in range(E):
			u, v = map(int, input().split())
			adj[u].append(v)
			adj[v].append(u)
		obj = Solution()
		ans = obj.criticalConnections(V, adj)
		for i in range(len(ans)):
		    print(ans[i][0],ans[i][1])

# } Driver Code Ends