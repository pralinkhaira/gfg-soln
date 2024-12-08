//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    struct Compare {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1]; 
        }
        return a[0] > b[0];
    }
};
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        for(auto &v:arr){
            pq.push(v);
        }
        vector<vector<int>> result;
        while(pq.size()>=2){
            vector<int> first=pq.top();
            pq.pop();
            vector<int> second=pq.top();
            pq.pop();
            if(first[1]>=second[0]){
                vector<int> ans={min(first[0],second[0]),max(first[1],second[1])};
                pq.push(ans);
            }else{
                result.push_back(first);
                pq.push(second);
            }
        }
        while(!pq.empty()){
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends