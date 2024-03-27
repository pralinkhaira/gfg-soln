//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> graph(n); // Adjacency list representation of the graph
        for (const auto& edge : edges) {
            int from = edge[0], to = edge[1], weight = edge[2];
            graph[from].emplace_back(to, weight);
            graph[to].emplace_back(from, weight); // Bidirectional edge
        }

        int minCities = numeric_limits<int>::max();
        int resultCity = -1;

        for (int start = 0; start < n; ++start) {
            vector<int> distance(n, numeric_limits<int>::max());
            distance[start] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min heap
            pq.push({0, start});

            while (!pq.empty()) {
                int dist = pq.top().first;
                int node = pq.top().second;
                pq.pop();

                if (dist > distance[node]) continue;

                for (const auto& neighbor : graph[node]) {
                    int nextNode = neighbor.first;
                    int weight = neighbor.second;
                    if (distance[node] + weight < distance[nextNode]) {
                        distance[nextNode] = distance[node] + weight;
                        pq.push({distance[nextNode], nextNode});
                    }
                }
            }

            int reachableCities = 0;
            for (int dist : distance) {
                if (dist <= distanceThreshold) {
                    ++reachableCities;
                }
            }

            if (reachableCities <= minCities) {
                minCities = reachableCities;
                resultCity = start;
            }
        }

        return resultCity;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends