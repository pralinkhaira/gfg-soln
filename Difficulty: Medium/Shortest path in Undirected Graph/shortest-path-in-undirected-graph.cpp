//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(vector<vector<int>>& edges, int n,int M, int src){
       vector<vector<int>>adj(n+1);
       for(auto &x:edges){
           adj[x[0]].push_back(x[1]);
           adj[x[1]].push_back(x[0]);
       }
     queue<int>pq;
       pq.push(src);
       vector<int>dist(n,INT_MAX);
       dist[src]=0;
       while(!pq.empty()){
           int node=pq.front();
           pq.pop();
           for(auto &x:adj[node]){
               if(dist[x]>dist[node]+1){
                   dist[x]=dist[node]+1;
                   pq.push(x);
               }
           }
       }
       for(auto &x:dist) {
           if(x==INT_MAX)x=-1;
       }
       return dist;
       
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends