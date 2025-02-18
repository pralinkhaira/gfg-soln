//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int dis(int x, int y){
       return (x*x)+(y*y);
   }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         vector<pair<int,pair<int,int>>>v;
         for(auto &i:points){
             int dist=dis(i[0],i[1]);
             v.push_back({dist,{i[0],i[1]}});
         }
         sort(v.begin(),v.end());
         vector<vector<int>>ans;
         for(int i=0;i<k;i++){
             ans.push_back({v[i].second.first,v[i].second.second});
         }
         return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends