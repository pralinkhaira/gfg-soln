//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int finding(int src,int dest,int V,vector<vector<int>>adj[])
    {
        vector<int>dist(V,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        dist[src]=0;
        while(!pq.empty())
        {
            auto &it=pq.top();
            int node=it.second;
            int d=it.first;
            pq.pop();
            for(auto& it:adj[node])
            {
                int adjN=it[0];
                int adjW=it[1];
                if((node==src && adjN==dest) || (node==dest && adjN==src))
                {
                    continue;
                }
                if(d+adjW<dist[adjN])
                {
                    dist[adjN]=d+adjW;
                    pq.push({dist[adjN],adjN});
                }
            }
        }
        return dist[dest];
    }
    int findMinCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj[V];
        for(auto &it:edges)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        int mini=1e9;
        int i;
        for(i=0;i<edges.size();i++)
        {
            int dist=(finding(edges[i][0],edges[i][1],V,adj));
            if(dist!=1e9)
            {
                mini=min(mini,dist+edges[i][2]);
            }
        }
        return mini;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }

        Solution obj;
        int res = obj.findMinCycle(V, edges);

        cout << res << endl;
    }

    return 0;
}
// } Driver Code Ends