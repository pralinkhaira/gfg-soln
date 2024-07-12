//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
         vector<pair<int , int >>adj[n+1];
        for( auto i : edges)
        {
            int u = i[0];
            int v = i[1];
            int weight = i[2];
            
            adj[u].push_back({v,weight});
            adj[v].push_back({u,weight});
        }
        
        vector<int> parent( n+1 , 0  );
        for( int i = 1 ; i<= n ;i++)
        parent[i] = i ;
        
    
        vector<int>dis( n+1 , 1e9);
        priority_queue< pair<int , int> , vector<pair<int, int>> , greater<pair<int , int>> >pq;        
        
        pq.push({0,1});
        dis[1] = 0 ;
        
        
        while( !pq.empty() )
        {
           auto it = pq.top();
           
           int distance = it.first ;
           int node = it.second;
           
           pq.pop();
           
           for( auto i : adj[node])
           {
               int adjnode =    i.first;
               int edgeweight = i.second;
               
               if( distance + edgeweight < dis[adjnode] )
               {
                   dis[adjnode] = distance + edgeweight ;
                   pq.push( {dis[adjnode] , adjnode });
                   parent[adjnode] = node;
               }
           }
        }
             
        if( dis[n] == 1e9 )
            return {-1} ;
            
            vector<int>path;
            int sum = dis[n];
            int node = n ;
            
            while( parent[node] != node)
            {
                
                // sum += dis[node];
                path.push_back(node);
                node = parent[node];
                
                
            }
            path.push_back(1);
            path.push_back(sum);
            reverse(path.begin() , path.end());
            
            
            return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends