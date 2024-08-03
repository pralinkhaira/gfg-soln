//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<pair<int,int>> mp;
        int i,j;
        for(i=0;i<n;i++)
        {
            mp.push_back({end[i],start[i]});
        }
        sort(mp.begin(),mp.end());
        int count=0;
        int intime=mp[0].first;
        for(i=0;i<n;i++)
        {
            if(mp[i].second>intime)
            {
                intime=mp[i].first;
                count++;
            }
        }
        return count+1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends