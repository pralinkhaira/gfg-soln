//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

#define UNVISITED -1
class Solution {
  
    public:
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        vector<set<int>> vertices(v);
        for(int i = 0; i < v; i++) vertices[i].insert(i);
        for(auto edge : edges) {
            vertices[edge[0]-1].insert(edge[1]-1);
            vertices[edge[1]-1].insert(edge[0]-1);
        }
        
        map<set<int>, int> sets;
        for(auto vertice : vertices) {
            auto it = sets.find(vertice);
            if(it != sets.end()) it->second--;
            else sets[vertice] = vertice.size();
        }
        
        int components = 0;
        for (auto it = sets.begin(); it != sets.end(); ++it) {
            components += (it->second == 1);
        }
        return components;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends