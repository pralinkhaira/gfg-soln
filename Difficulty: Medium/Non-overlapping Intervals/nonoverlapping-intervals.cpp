//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  static bool compare(vector<int>&a,vector<int>&b){
       return a[1]<b[1];
  }
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),compare);
        int ans=0;
        int lastend=intervals[0][1];
        for(int i=1;i<n;i++){
            if(lastend > intervals[i][0]){
                ans++;
                lastend = min(lastend , intervals[i][1]);
            }
            else{
                lastend = intervals[i][1];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends