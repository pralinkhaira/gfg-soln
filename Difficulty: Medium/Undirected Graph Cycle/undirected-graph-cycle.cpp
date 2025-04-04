//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int>vis;
    bool f(int src,int p,vector<vector<int>>&adj){
        vis[src]=1;
        
        for(auto&it:adj[src]){
            if(!vis[it]){
                if(f(it,src,adj))return 1;
            }
            else{
                if(it!=p){
                    return 1;
                }
            }
        }
        return 0;
        // vis[src]=1;
        
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(auto&it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vis.assign(V,0);
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(f(i, -1, adj)) return true;
            }
        }
        return false;

    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends