//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool help(int node,vector<int>&vis,vector<int>&rec,vector<vector<int>>&adj){
      
      vis[node]=true;
      rec[node]=true;
      for(auto &x:adj[node])
      {
          
          if(rec[x]) return true;
          if(help(x,vis,rec,adj)) return true;
      }
      rec[node]=false;
      return false;
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V+1);
        for(auto &x:edges)
        {
            adj[x[0]].push_back(x[1]);
        }
        vector<int>vis(V+1,false),rec(V+1,false);
        
        bool flag=false;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                flag|=help(i,vis,rec,adj);
            }
        }
        return flag;
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
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends